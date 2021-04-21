#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include "creerclientwindow.h"
//#include "clientdao.cpp"

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = 0);
    ~ClientWindow();
    CreerClientWindow ccw;
    client*c=new client();
    clientdao*cdao=new clientdao();


private slots:
    void on_bouton_creer_clicked();

    void on_bouton_rechercher_clicked();

    void on_btn_rafraichir_clicked();

    void on_bouton_supprimer_clicked();

private:
    Ui::ClientWindow *ui;
    void initTableView();
};

#endif // CLIENTWINDOW_H
