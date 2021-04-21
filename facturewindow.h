#ifndef FACTUREWINDOW_H
#define FACTUREWINDOW_H

#include <QMainWindow>
#include "creerfacturewindow.h"

namespace Ui {
class facturewindow;
}

class facturewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit facturewindow(QWidget *parent = 0);
    ~facturewindow();
    creerfacturewindow cfw;
    facture*f=new facture();
    facturedao*fdao=new facturedao();

private slots:
    void on_btn_creer_clicked();

    void on_btn_supprimer_clicked();

    void on_btn_rechercher_clicked();

    void on_btn_rafraichir_clicked();

private:
    Ui::facturewindow *ui;
    void initTableView();
};

#endif // FACTUREWINDOW_H
