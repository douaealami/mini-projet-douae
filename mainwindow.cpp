#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_client_clicked()
{
    this->cw.show();
}

void MainWindow::on_btn_departement_clicked()
{
    this->dw.show();
}

void MainWindow::on_btn_categorie_clicked()
{
    this->cat_w.show();
}

void MainWindow::on_btn_produits_clicked()
{
    this->pw.show();
}

void MainWindow::on_btn_quitter_clicked()
{
    QApplication::exit();
    delete ui;
}

void MainWindow::on_btn_commandes_clicked()
{
    this->cmdw.show();
}

void MainWindow::on_btn_factures_clicked()
{
    this->fw.show();
}
