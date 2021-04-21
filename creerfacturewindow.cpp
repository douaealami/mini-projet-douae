#include "creerfacturewindow.h"
#include "ui_creerfacturewindow.h"
#include "qguiutils.cpp"

creerfacturewindow::creerfacturewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::creerfacturewindow)
{
    ui->setupUi(this);
}

creerfacturewindow::~creerfacturewindow()
{
    delete ui;
}

void creerfacturewindow::on_bouton_enregistrer_clicked()
{

    int cmd_num=ui->txt_num_cmd->text().toInt();
    int cmd_prod_num=ui->txt_num_prod_cmd->text().toInt();
    int cmd_quantite=ui->txt_quantite->text().toInt();
    int cmd_prod_prix=ui->txt_prix->text().toInt();
    int cmd_total=ui->txt_total->text().toInt();

    QGuiUtils*gu=new QGuiUtils();
    if(
            this->ui->txt_num_cmd->text().isEmpty() ||
            this->ui->txt_num_prod_cmd->text().isEmpty() ||
            this->ui->txt_quantite->text().isEmpty() ||
            this->ui->txt_prix->text().isEmpty() ||
            this->ui->txt_total->text().isEmpty()
            ) {
        gu->MsgBox("Alerte","Veuillez saisir les champs vides");
    }
    else {
        try {
          this->f->setCmdNum(cmd_num);
            this->f->setCmdProdNum(cmd_prod_num);
            this->f->setCmdQuantite(cmd_quantite);
            this->f->setCmdProdPrix(cmd_prod_prix);
            this->f->setCmdTotal(cmd_total);
        bool create=this->fdao->create(f);


        if(create) {
            gu->MsgBox("Success","Facture créée avec succès");
        }
        else {
            gu->MsgBox("Error","Echec de l'ajout de la facture");
        }
        }
        catch(QException&ex) {
            ex.raise();
        }

    }
}
