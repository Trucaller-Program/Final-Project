#ifndef SEARCHNUMBERSCENE_H
#define SEARCHNUMBERSCENE_H

#include <QDialog>

namespace Ui {
class SearchNumberScene;
}

class SearchNumberScene : public QDialog
{
    Q_OBJECT

public:
    explicit SearchNumberScene(QWidget *parent = nullptr);
    ~SearchNumberScene();

private slots:
    void on_pushButton13_clicked();

    void on_pushButton11_clicked();

    void on_pushButton12_clicked();

    void on_lineEdit11_selectionChanged();

private:
    Ui::SearchNumberScene *ui;
};

#endif // SEARCHNUMBERSCENE_H
