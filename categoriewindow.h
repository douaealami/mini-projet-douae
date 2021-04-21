#ifndef CATEGORIEWINDOW_H
#define CATEGORIEWINDOW_H

#include <QMainWindow>
#include "creercategoriewindow.h"

namespace Ui {
class categoriewindow;
}

class categoriewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit categoriewindow(QWidget *parent = 0);
    ~categoriewindow();
    creercategoriewindow ccw;
    categorie*c=new categorie();
    categoriedao*cdao=new categoriedao();


private slots:
    void on_btn_creer_clicked();

    void on_btn_supprimer_clicked();

    void on_btn_rechercher_clicked();

    void on_btn_rafraichir_clicked();

private:
    Ui::categoriewindow *ui;
    void initTableView();
};

#endif // CATEGORIEWINDOW_H
