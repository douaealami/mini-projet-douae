#include "creercommandewindow.h"
#include "ui_creercommandewindow.h"
#include "qguiutils.cpp"

creercommandewindow::creercommandewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::creercommandewindow)
{
    ui->setupUi(this);
}

creercommandewindow::~creercommandewindow()
{
    delete ui;
}

void creercommandewindow::on_bouton_enregistrer_clicked()
{
    QGuiUtils*gu=new QGuiUtils();
    if(this->ui->txt_num_cli->text().isEmpty()) {
        gu->MsgBox("Alerte","Veuillez saisir les champs vides.");
    }
    else {
        try {
        this->c->setCmdDate(ui->date_commande->date());
        this->c->setCmdStatut(ui->combo_statut->currentText());
        this->c->setCliNum(ui->txt_num_cli->text().toInt());
        bool create=this->cdao->create(c);


        if(create) {
            gu->MsgBox("Success","Commande créée avec succès.");
        }
        else {
            gu->MsgBox("Error","Echec de la création de la commande.");
        }
        }
        catch(QException&ex) {
            ex.raise();
        }

    }
}
