#include "loginscene.h"
#include "ui_loginscene.h"
#include "searchingscene.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>


LoginScene::LoginScene(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginScene)
{
    ui->setupUi(this);
    ui->pushButton_exit2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton_login2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->lineEdit_pass2->setReadOnly(1);

}



LoginScene::~LoginScene()
{
    delete ui;
}



void LoginScene::on_pushButton_exit2_clicked(){
    this->close();

}


void LoginScene::on_pushButton_login2_clicked(){
    QFile Register("Register.txt");
       if(!Register.exists()){
           qDebug()<<"File doesn't exist ";
       }

       if(!Register.open(QIODevice::ReadOnly)) {
           QMessageBox::information(0, "error", Register.errorString());
       }

       QString userMail=ui->lineEdit_mail2->text();
       QString userPass=ui->lineEdit_pass2->text();

       QTextStream in(&Register);
       bool found = false;

       while (!in.atEnd()) {
           QString line = in.readLine();
           if(line==NULL){
               break;
           }
           QStringList fields = line.split(",");
           QString password=fields.at(1);
           QString mail=fields.at(0);
           if(mail == userMail){
               found = true;
               if(password == userPass){
                   SearchingScene searchingScreen;
                   searchingScreen.show();
                   searchingScreen.setModal(true);
                   searchingScreen.setWindowState(Qt::WindowFullScreen);
                   searchingScreen.exec();
                   this->hide();
               }
               else {
                   QMessageBox::warning(this," Login ","Wrong Password! Please Try Again ");
               }
           }
           if(found)
               break;
       }
       Register.close();
       if(!found) {
           QMessageBox::warning(this," Login ","Email is not found");
       }
}


void LoginScene::on_lineEdit_pass2_selectionChanged()
{
    ui->lineEdit_pass2->setText("");
    ui->lineEdit_pass2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_pass2->setReadOnly(0);
}

