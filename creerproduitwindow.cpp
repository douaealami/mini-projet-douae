#include "creerproduitwindow.h"
#include "ui_creerproduitwindow.h"
#include <QFileDialog>
#include "qguiutils.cpp"

creerproduitwindow::creerproduitwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::creerproduitwindow)
{
    ui->setupUi(this);
}

creerproduitwindow::~creerproduitwindow()
{
    delete ui;
}

void creerproduitwindow::on_btn_rechercher_img_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Choisir une image"), "",
            tr("Image (*.jpg);;All Files (*)"));

    if(!fileName.isEmpty()) {
        ui->label_nom_fichier->setText(fileName);
    }
}

void creerproduitwindow::on_bouton_enregistrer_clicked()
{
    QString nom=ui->txt_nom->text();
    QString description=ui->txt_description->text();
    int prix=ui->txt_prix->text().toInt();
    QString image=ui->label_nom_fichier->text();
    int cat_num=ui->txt_cat_id->text().toInt();

    QGuiUtils*gu=new QGuiUtils();
    if(
            this->ui->txt_nom->text().isEmpty() ||
            this->ui->txt_description->text().isEmpty() ||
            this->ui->txt_prix->text().isEmpty() ||
            this->ui->label_nom_fichier->text().isEmpty() ||
            this->ui->txt_cat_id->text().isEmpty()
            ) {
        gu->MsgBox("Alerte","Veuillez saisir les champs vides");
    }
    else {
        try {
        this->p->setPProdNom(nom);
        this->p->setPProdPrix(prix);
        this->p->setPProdImage(image);
        this->p->setPProdDescription(description);
        this->p->setCatNum(cat_num);
        bool create=this->pdao->create(p);


        if(create) {
            gu->MsgBox("Success","Produit créé avec succès");
        }
        else {
            gu->MsgBox("Error","Echec de l'ajout du produit");
        }
        }
        catch(QException&ex) {
            ex.raise();
        }

    }
}
