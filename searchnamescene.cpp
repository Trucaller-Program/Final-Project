#include "searchnamescene.h"
#include "ui_searchnamescene.h"
#include "searchingscene.h"
#include "chaining.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>

SearchNameScene::SearchNameScene(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchNameScene)
{
    ui->setupUi(this);
    ui->pushButton_search1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->lineEdit_search->setPlaceholderText("Enter a Name");
    ui->lineEdit_search->setReadOnly(1);


}

SearchNameScene::~SearchNameScene()
{
    delete ui;

}

void SearchNameScene::on_pushButton_search1_clicked(){
        Chaining chaining;
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
            chaining.insert_chaining(nameString,numberString);
        }
        myFile.close();

        QString name =ui->lineEdit_search->text();
        string nameString = name.toStdString();
        string returnedValue = chaining.searchName_chaining(nameString);
        QString qstr = QString::fromStdString(returnedValue);
        QMessageBox::information(this,"Search by name ",qstr);

}


void SearchNameScene::on_lineEdit_search_selectionChanged()
{
    ui->lineEdit_search->setText("");
    ui->lineEdit_search->setReadOnly(0);
}


void SearchNameScene::on_pushButton_clicked(){
    SearchingScene search;
    search.show();
    search.setModal(true);
    search.setWindowState(Qt::WindowFullScreen);
    search.exec();
    this->hide();

}


void SearchNameScene::on_pushButton1_clicked()
{
    this->close();
}

