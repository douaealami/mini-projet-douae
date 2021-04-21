#include "categoriewindow.h"
#include "ui_categoriewindow.h"
#include "qguiutils.cpp"
#include <QInputDialog>

categoriewindow::categoriewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::categoriewindow)
{
    ui->setupUi(this);
    this->initTableView();
}

void categoriewindow::initTableView() {
    this->cdao->list(ui->tableCategorie);
}

categoriewindow::~categoriewindow()
{
    this->hide();
    delete ui;
}



void categoriewindow::on_btn_creer_clicked()
{
    this->ccw.show();
}

void categoriewindow::on_btn_supprimer_clicked()
{
    QString num = QInputDialog::getText(this, "Supprimer catégorie", "Entrer le num catégorie:", QLineEdit::Normal, QString(), false);
    int cat_num=num.toInt();
    QGuiUtils*gutils=new QGuiUtils();

    if(num.isEmpty()) {
        gutils->MsgBox("Erreur","Veuillez saisir le numéro catégorie");
    }
    else {
        try {
          bool remove= this->cdao->remove(cat_num);

          if(remove) {
              gutils->MsgBox("Info","Catégorie supprimé avec succès.");
              this->initTableView();
          }
          else {
              gutils->MsgBox("Echec","Echec de la suppression de la catégorie.");
          }
        }
        catch(QException&ex) {
            ex.raise();
        }
    }
}

void categoriewindow::on_btn_rechercher_clicked()
{
    QString num = QInputDialog::getText(this, "Rechercher catégorie", "Entrer le num catégorie:", QLineEdit::Normal, QString(), false);
    int cat_num=num.toInt();
    QGuiUtils*gutils=new QGuiUtils();

    if(num.isEmpty()) {
        gutils->MsgBox("Erreur","Veuillez saisir le numéro catégorie");
    }
    else {
        try {
          categorie ct=  this->cdao->search(cat_num);
          gutils->MsgBox("Info","<b>Nom: </b>"+ct.getCatNom()+"<br><b>Num département: </b>"+ct.getDepNum());

        }
        catch(QException&ex) {
            ex.raise();
        }
    }
}

void categoriewindow::on_btn_rafraichir_clicked()
{
    this->initTableView();
}
