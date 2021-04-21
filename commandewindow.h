#ifndef COMMANDEWINDOW_H
#define COMMANDEWINDOW_H

#include <QMainWindow>
#include "creercommandewindow.h"

namespace Ui {
class commandewindow;
}

class commandewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit commandewindow(QWidget *parent = 0);
    ~commandewindow();
    creercommandewindow ccw;
    commande*c=new commande();
    commandedao*cdao=new commandedao();

private slots:
    void on_btn_creer_clicked();

    void on_btn_supprimer_clicked();

    void on_btn_rechercher_clicked();

    void on_btn_rafraichir_clicked();

private:
    Ui::commandewindow *ui;
    void initTableView();
};

#endif // COMMANDEWINDOW_H
