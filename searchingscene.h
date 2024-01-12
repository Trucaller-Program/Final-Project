#ifndef SEARCHINGSCENE_H
#define SEARCHINGSCENE_H

#include <QDialog>

namespace Ui {
class SearchingScene;
}

class SearchingScene : public QDialog
{
    Q_OBJECT

public:
    explicit SearchingScene(QWidget *parent = nullptr);
    ~SearchingScene();

private slots:
    void on_pushButton_close3_clicked();

    void on_pushButton_searchName_clicked();

    void on_pushButton_exit3_clicked();

    void on_pushButton_searchNumber_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_num_clicked();

private:
    Ui::SearchingScene *ui;
};

#endif // SEARCHINGSCENE_H
