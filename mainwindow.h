#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <clientwindow.h>
#include <departementwindow.h>
#include <categoriewindow.h>
#include <produitwindow.h>
#include <commandewindow.h>
#include <facturewindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ClientWindow cw;
    DepartementWindow dw;
    categoriewindow cat_w;
    produitwindow pw;
    commandewindow cmdw;
    facturewindow fw;

private slots:
    void on_btn_client_clicked();

    void on_btn_departement_clicked();

    void on_btn_categorie_clicked();

    void on_btn_produits_clicked();

    void on_btn_quitter_clicked();

    void on_btn_commandes_clicked();

    void on_btn_factures_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
