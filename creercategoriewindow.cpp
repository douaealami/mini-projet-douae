#include "creercategoriewindow.h"
#include "ui_creercategoriewindow.h"
#include "qguiutils.cpp"

creercategoriewindow::creercategoriewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::creercategoriewindow)
{
    ui->setupUi(this);
}

creercategoriewindow::~creercategoriewindow()
{
    delete ui;
}

void creercategoriewindow::on_bouton_enregistrer_clicked()
{
    QGuiUtils*gu=new QGuiUtils();
    if(this->ui->txt_nom->text().isEmpty() || this->ui->txt_dep_num->text().isEmpty() ) {
        gu->MsgBox("Warning","Veuillez saisir les champs vides.");
    }
    else {

        try {
        QString nom=ui->txt_nom->text();
        QString dep=ui->txt_dep_num->text();
        int dep_num=dep.toInt();
        this->c->setCatNom(nom);
        this->c->setDepNum(dep_num);
        qDebug()<<"dep_num="<<c->getDepNum();
        bool create=this->cdao->create(c);


        if(create) {
            gu->MsgBox("Success","Catégorie créée avec succès.");
        }
        else {
            gu->MsgBox("Error","Echec de la création de la catégorie");
        }
        }
        catch(QException&ex) {
            qDebug()<<ex.what();
        }
    }
}
