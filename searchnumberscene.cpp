#include "searchnumberscene.h"
#include "ui_searchnumberscene.h"
#include "searchingscene.h"
#include "hashtable.h"
#include <QFile>
#include <QDebug>
#include<QMessagebox>


SearchNumberScene::SearchNumberScene(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchNumberScene)
{
    ui->setupUi(this);
    ui->pushButton13->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton11->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton12->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->lineEdit11->setPlaceholderText("Enter a Number");
    ui->lineEdit11->setReadOnly(1);
}

SearchNumberScene::~SearchNumberScene()
{
    delete ui;
}

void SearchNumberScene::on_pushButton13_clicked()
{
    SearchingScene searchingScreen;
    searchingScreen.show();
    searchingScreen.setModal(true);
    searchingScreen.setWindowState(Qt::WindowFullScreen);
    searchingScreen.exec();
    this->hide();
}


void SearchNumberScene::on_pushButton11_clicked()
{
    this->close();
}


void SearchNumberScene::on_pushButton12_clicked()
{
    HashTable hashtable;
    QFile myFile("Register.txt");
    QTextStream in(&myFile);

    if(!myFile.exists()){
        qDebug() << "File doesn't exist!";
        return;
    }

    if(!myFile.open(QIODevice::ReadOnly)){
        qDebug() << "Unable to open file!";
        return;
    }

    while(!in.atEnd()){
        QString line = in.readLine();
        if(line==NULL){
            break;
        }
        QStringList fields = line.split(",");
        QString name = fields.at(2);
        QString number = fields.at(3);
        string nameString = name.toStdString();
        string numberString = number.toStdString();
        hashtable.insert_double(nameString,numberString);
    }
    myFile.close();

    QString number =ui->lineEdit11->text();
    string numberString = number.toStdString();
    string returnedValue = hashtable.searchNumber_double(numberString);
    QString qstr = QString::fromStdString(returnedValue);
    QMessageBox::information(this,"Search by name ",qstr);
}


void SearchNumberScene::on_lineEdit11_selectionChanged()
{
    ui->lineEdit11->setText("");
    ui->lineEdit11->setReadOnly(0);
}

