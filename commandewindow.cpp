#include "commandewindow.h"
#include "ui_commandewindow.h"
#include <QInputDialog>
#include "qguiutils.cpp"

commandewindow::commandewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::commandewindow)
{
    ui->setupUi(this);

    this->initTableView();
}

commandewindow::~commandewindow()
{
    delete ui;
}

void commandewindow::initTableView() {
   this->cdao->list(this->ui->tableCommande);
}

void commandewindow::on_btn_creer_clicked()
{
    this->ccw.show();
}

void commandewindow::on_btn_supprimer_clicked()
{
    QString num = QInputDialog::getText(this, "Supprimer commande", "Entrer le num commande:", QLineEdit::Normal, QString(), false);
    int cmd_num=num.toInt();
    QGuiUtils*gutils=new QGuiUtils();

    if(num.isEmpty()) {
        gutils->MsgBox("Erreur","Veuillez saisir le numéro commande");
    }
    else {
        try {
          bool remove= this->cdao->remove(cmd_num);

          if(remove) {
              gutils->MsgBox("Info","Commande supprimée avec succès.");
              this->initTableView();
          }
          else {
              gutils->MsgBox("Echec","Echec de la suppression de la commande.");
          }
        }
        catch(QException&ex) {
            ex.raise();
        }
    }
}

void commandewindow::on_btn_rechercher_clicked()
{
    QString num = QInputDialog::getText(this, "Rechercher commende", "Entrer le num commande:", QLineEdit::Normal, QString(), false);
    int cmd_num=num.toInt();
    QGuiUtils*gutils=new QGuiUtils();

    if(num.isEmpty()) {
        gutils->MsgBox("Erreur","Veuillez saisir le numéro commande");
    }
    else {
        try {
          commande cmd=  this->cdao->search(cmd_num);

          gutils->MsgBox("Info","<b>Date: </b>"+(cmd.getCmdDate().toString())+"<br><b>Statut: </b>"+cmd.getCmdStatut()+"<br><b>Id. Client: </b>"+QString::number(cmd.getCliNum()));
        }
        catch(QException&ex) {
            ex.raise();
        }
    }
}

void commandewindow::on_btn_rafraichir_clicked()
{
    this->initTableView();
}
