#ifndef CREERCLIENTWINDOW_H
#define CREERCLIENTWINDOW_H

#include <QMainWindow>
#include "clientdao.cpp"
//#include "qguiutils.cpp"

namespace Ui {
class CreerClientWindow;
}

class CreerClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreerClientWindow(QWidget *parent = 0);
    ~CreerClientWindow();
    clientdao*cdao=new clientdao();
    client*c=new client();
//    QGuiUtils*gu=new QGuiUtils();

private slots:
    void on_bouton_enregistrer_clicked();

private:
    Ui::CreerClientWindow *ui;
};

#endif // CREERCLIENTWINDOW_H
