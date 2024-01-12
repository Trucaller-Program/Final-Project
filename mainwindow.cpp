#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chaining.h"
#include "hashtable.h"
#include "loginscene.h"
#include <QMessageBox>
#include <QScreen>
#include <QDebug>


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->pushButton_SignUp_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton_LogIn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton_exit->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->lineEdit_password->setReadOnly(1);
}



MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_pushButton_SignUp_2_clicked(){
    QFile Register("Register.txt");
    bool found = false;

    QString name=ui->lineEdit_name->text();
    QString number=ui->lineEdit_num->text();
    QString mail=ui->lineEdit_mail->text();
    QString pass=ui->lineEdit_password->text();


    if(mail==NULL||name==NULL||pass==NULL||number==NULL)
        QMessageBox::warning(this," Login "," Data is not completed ");

     else if (mail != NULL && name!=NULL&&pass!=NULL&&number!=NULL ){
        if(Register.open(QIODevice::ReadOnly)){
        QTextStream in(&Register);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            QString fileMail = fields.at(0);
        if(fileMail == mail)
            found = true;
        }
        Register.close();
     }
     if(found)
        QMessageBox::warning(this," Login "," This email is used before ");

      else{
        if(Register.open(QIODevice::Append | QIODevice::ReadWrite)){
             QTextStream stream(&Register);
             stream << mail << "," << pass << "," << name << "," << number << endl;
          }
          Register.close();

          QMessageBox::information(this," Login "," Your Email and password are successfuly saved");

           LoginScene loginscreen;
           loginscreen.show();
           loginscreen.setModal(true);
           loginscreen.setWindowState(Qt::WindowFullScreen);
           loginscreen.exec();
           this->hide();
       }
     }
}

void MainWindow::on_pushButton_LogIn_clicked(){
    LoginScene logIn;
    logIn.show();
    logIn.setModal(true);
    logIn.setWindowState(Qt::WindowFullScreen);
    logIn.exec();
    this->hide();

}


void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}


void MainWindow::on_lineEdit_password_selectionChanged()
{
    ui->lineEdit_password->setText("");
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_password->setReadOnly(0);
}

