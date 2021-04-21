#ifndef WINDOWLOGIN_H
#define WINDOWLOGIN_H

#include <QMainWindow>
//#include "utilisateur.cpp"
#include "utilisateurdao.cpp"
//#include "dbhelper.cpp"
#include "QGuiUtils.cpp"
#include <mainwindow.h>


namespace Ui {
class WindowLogin;
}

class WindowLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowLogin(QWidget *parent = 0);
    ~WindowLogin();
    utilisateur*u=new utilisateur();

    utilisateurdao*udao=new utilisateurdao();
    //dbhelper dbh;
    QGuiUtils*gu=new QGuiUtils();
    MainWindow mw;


private slots:
    void on_pushButton_clicked();

private:
    Ui::WindowLogin *ui;

};

#endif // WINDOWLOGIN_H
