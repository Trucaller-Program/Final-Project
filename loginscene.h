#ifndef LOGINSCENE_H
#define LOGINSCENE_H

#include <QDialog>

namespace Ui {
class LoginScene;
}

class LoginScene : public QDialog
{
    Q_OBJECT

public:
    explicit LoginScene(QWidget *parent = nullptr);
    ~LoginScene();

private slots:
    void on_pushButton_exit2_clicked();

    void on_pushButton_login2_clicked();

    void on_lineEdit_mail2_textChanged(const QString &arg1);

    void on_lineEdit_pass2_selectionChanged();

private:
    Ui::LoginScene *ui;
};

#endif // LOGINSCENE_H
