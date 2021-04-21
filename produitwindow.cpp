#include "produitwindow.h"
#include "ui_produitwindow.h"
#include <QInputDialog>
#include "qguiutils.cpp"

produitwindow::produitwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::produitwindow)
{
    ui->setupUi(this);
    this->initTableView();
}

produitwindow::~produitwindow()
{
    delete ui;
}

void produitwindow::on_btn_creer_clicked()
{
    this->cpw.show();
}

void produitwindow::initTableView() {
   this->pdao->list(this->ui->tableProduit);
}
void produitwindow::on_btn_supprimer_clicked()
{
    QString num = QInputDialog::getText(this, "Supprimer produit", "Entrer le num produit:", QLineEdit::Normal, QString(), false);
    int prod_num=num.toInt();
    QGuiUtils*gutils=new QGuiUtils();

    if(num.isEmpty()) {
        gutils->MsgBox("Erreur","Veuillez saisir le numéro produit");
    }
    else {
        try {
          bool remove=  this->pdao->remove(prod_num);

          if(remove) {
              gutils->MsgBox("Info","Produit supprimé avec succès.");
              this->initTableView();
          }
          else {
              gutils->MsgBox("Echec","Echec de la suppression du produit.");
          }
        }
        catch(QException&ex) {
            ex.raise();
        }
    }
}

void produitwindow::on_btn_rechercher_clicked()
{
    QString num = QInputDialog::getText(this, "Rechercher produit", "Entrer le num produit:", QLineEdit::Normal, QString(), false);
    int prod_num=num.toInt();
    QGuiUtils*gutils=new QGuiUtils();

    if(num.isEmpty()) {
        gutils->MsgBox("Erreur","Veuillez saisir le numéro client");
    }
    else {
        try {
          produit prd=  this->pdao->search(prod_num);

          gutils->MsgBox("Info","<b>Nom: </b>"+prd.getPProdNom()+"<br><b>Description: </b>"+prd.getPProdDescription()+"<br><b>Prix: </b>"+QString::number(prd.getPProdPrix())+"<br><b>Num. Catégorie: </b>"+QString::number(prd.getCatNum()));
          //    this->initTableView();
        }
        catch(QException&ex) {
            ex.raise();
        }
    }
}

void produitwindow::on_btn_rafraichir_clicked()
{
    this->initTableView();
}
