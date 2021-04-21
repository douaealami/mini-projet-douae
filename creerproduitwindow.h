#ifndef CREERPRODUITWINDOW_H
#define CREERPRODUITWINDOW_H

#include <QMainWindow>
#include "produitdao.cpp"

namespace Ui {
class creerproduitwindow;
}

class creerproduitwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit creerproduitwindow(QWidget *parent = 0);
    ~creerproduitwindow();
    produitdao*pdao=new produitdao();
    produit*p=new produit();

private slots:
    void on_btn_rechercher_img_clicked();

    void on_bouton_enregistrer_clicked();

private:
    Ui::creerproduitwindow *ui;
};

#endif // CREERPRODUITWINDOW_H
