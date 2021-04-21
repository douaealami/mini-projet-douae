#ifndef PRODUITWINDOW_H
#define PRODUITWINDOW_H

#include <QMainWindow>
#include "creerproduitwindow.h"

namespace Ui {
class produitwindow;
}

class produitwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit produitwindow(QWidget *parent = 0);
    ~produitwindow();
    creerproduitwindow cpw;
    produit*p=new produit();
    produitdao*pdao=new produitdao();

private slots:
    void on_btn_creer_clicked();

    void on_btn_supprimer_clicked();

    void on_btn_rechercher_clicked();

    void on_btn_rafraichir_clicked();

private:
    Ui::produitwindow *ui;
    void initTableView();
};

#endif // PRODUITWINDOW_H
