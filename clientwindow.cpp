#include "clientwindow.h"
#include "ui_clientwindow.h"
#include <QInputDialog>
#include "qguiutils.cpp"

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);

    this->initTableView();
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_bouton_creer_clicked()
{
    this->ccw.show();
}

void ClientWindow::initTableView() {
   this->cdao->list(this->ui->tableClient);
}

void ClientWindow::on_bouton_rechercher_clicked()
{
    QString num = QInputDialog::getText(this, "Rechercher client", "Entrer le num client:", QLineEdit::Normal, QString(), false);
    int cli_num=num.toInt();
    qDebug()<<"cli_num"<<cli_num;
    QGuiUtils*gutils=new QGuiUtils();

    if(num.isEmpty()) {
        gutils->MsgBox("Erreur","Veuillez saisir le numéro client");
    }
    else {
        try {
          client clt=  this->cdao->search(cli_num);

          gutils->MsgBox("Info","<b>Nom: </b>"+clt.getCliNom()+"<br><b>Date de naissance: </b>"+clt.getCliDatenaissance().toString("dd/MM/yyyy")+"<br><b>Téléphone: </b>"+clt.getCliTel());
          //    this->initTableView();
        }
        catch(QException&ex) {
            ex.raise();
        }
    }

}

void ClientWindow::on_btn_rafraichir_clicked()
{
    this->initTableView();
}

void ClientWindow::on_bouton_supprimer_clicked()
{
    QString num = QInputDialog::getText(this, "Supprimer client", "Entrer le num client:", QLineEdit::Normal, QString(), false);
    int cli_num=num.toInt();
    qDebug()<<"cli_num"<<cli_num;
    QGuiUtils*gutils=new QGuiUtils();

    if(num.isEmpty()) {
        gutils->MsgBox("Erreur","Veuillez saisir le numéro client");
    }
    else {
        try {
          bool remove=  this->cdao->remove(cli_num);

          if(remove) {
              gutils->MsgBox("Info","Client supprimé avec succès.");
              this->initTableView();
          }
          else {
              gutils->MsgBox("Echec","Echec de la suppression du client.");
          }
        }
        catch(QException&ex) {
            ex.raise();
        }
    }
}
