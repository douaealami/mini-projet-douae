#include "facturewindow.h"
#include "ui_facturewindow.h"
#include "qguiutils.cpp"
#include <QInputDialog>

facturewindow::facturewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::facturewindow)
{
    ui->setupUi(this);
    this->initTableView();
}

facturewindow::~facturewindow()
{
    delete ui;
}

void facturewindow::initTableView() {
    this->fdao->list(ui->tableFacture);
}

void facturewindow::on_btn_creer_clicked()
{
    this->cfw.show();
}

void facturewindow::on_btn_supprimer_clicked()
{
    QGuiUtils*gutils=new QGuiUtils();
    QString num  = QInputDialog::getText(this, "Supprimer facture", "Entrez le num de facture", QLineEdit::Normal, QString(), false);


      if(num.isEmpty()) {
           gutils->MsgBox("Erreur","Veuillez saisir le num de facture.");
      }
      else {
         try {
              int fac_num=num.toInt();
              bool del=this->fdao->remove(fac_num);
              if(del) {
              initTableView();
              }
              else {
                  gutils->MsgBox("Echec","Echec de la suppression de la facture.");
              }
          }
          catch(QException&ex) {
              ex.raise();
          }
      }
}

void facturewindow::on_btn_rechercher_clicked()
{

}

void facturewindow::on_btn_rafraichir_clicked()
{
    this->initTableView();
}
