#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QString>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void savingData();
    ~MainWindow();

private slots:
    void on_pushButton_SignUp_2_clicked();

    void on_pushButton_LogIn_clicked();

    void on_pushButton_exit_clicked();

    void on_lineEdit_password_selectionChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
