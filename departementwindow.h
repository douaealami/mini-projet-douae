#ifndef DEPARTEMENTWINDOW_H
#define DEPARTEMENTWINDOW_H

#include <QMainWindow>
#include "departementdao.cpp"
#include <QInputDialog>

namespace Ui {
class DepartementWindow;
}

class DepartementWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DepartementWindow(QWidget *parent = 0);
    ~DepartementWindow();
    departement*dep=new departement();
    departementdao*dep_dao=new departementdao();
private slots:
    void on_btn_creer_clicked();

    void on_btn_supprimer_clicked();

    void on_btn_rafraichir_clicked();

    void on_btn_rechercher_clicked();

private:
    Ui::DepartementWindow *ui;
    void initTableView();
};

#endif // DEPARTEMENTWINDOW_H
