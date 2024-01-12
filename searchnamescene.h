#ifndef SEARCHNAMESCENE_H
#define SEARCHNAMESCENE_H

#include <QDialog>

namespace Ui {
class SearchNameScene;
}

class SearchNameScene : public QDialog
{
    Q_OBJECT

public:
    explicit SearchNameScene(QWidget *parent = nullptr);
    ~SearchNameScene();

private slots:
    void on_pushButton_search1_clicked();

    void on_lineEdit_search_selectionChanged();

    void on_pushButton_clicked();

    void on_pushButton1_clicked();

private:
    Ui::SearchNameScene *ui;
};

#endif // SEARCHNAMESCENE_H
