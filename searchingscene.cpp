#include "searchingscene.h"
#include "ui_searchingscene.h"
#include "searchnamescene.h"
#include "searchnumberscene.h"

SearchingScene::SearchingScene(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchingScene)
{
    ui->setupUi(this);
    ui->pushButton_close->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton_searchName->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pushButton_num->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

}

SearchingScene::~SearchingScene()
{
    delete ui;
}


void SearchingScene::on_pushButton_close_clicked(){
    this->close();

}

void SearchingScene::on_pushButton_searchName_clicked(){
    SearchNameScene searchName;
    searchName.show();
    searchName.setModal(true);
    searchName.setWindowState(Qt::WindowFullScreen);
    searchName.exec();
    this->hide();
}

void SearchingScene::on_pushButton_num_clicked()
{
    SearchNumberScene searchNum;
    searchNum.show();
    searchNum.setModal(true);
    searchNum.setWindowState(Qt::WindowFullScreen);
    searchNum.exec();
    this->hide();
}

