#include "departementwindow.h"
#include "ui_departementwindow.h"
#include "qguiutils.cpp"

DepartementWindow::DepartementWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DepartementWindow)
{
    ui->setupUi(this);
    initTableView();
}

DepartementWindow::~DepartementWindow()
{
    delete ui;
}

void DepartementWindow::initTableView() {
    this->dep_dao->list(this->ui->tableDepartement);
}

void DepartementWindow::on_btn_creer_clicked()
{
    QString dep_nom = QInputDialog::getText(this, "Nouveau département", "Entrez le nom du département", QLineEdit::Normal, QString(), false);
     QGuiUtils*gutils=new QGuiUtils();

    if(dep_nom.isEmpty()) {
        gutils->MsgBox("Erreur","Veuillez saisir le nom du département.");
    }
    else {
        try {
            this->dep->setDDepNom(dep_nom);

            bool create=this->dep_dao->create(dep);
            if(create) {
                gutils->MsgBox("Info","Département créé avec succès.");
            initTableView();
            }
            else {
                gutils->MsgBox("Echec","Echec de la création du département");
            }
        }
        catch(QException&ex) {
            ex.raise();
        }
    }
}

void DepartementWindow::on_btn_supprimer_clicked()
{
    QGuiUtils*gutils=new QGuiUtils();
    QString num  = QInputDialog::getText(this, "Supprimer département", "Entrez le num du département", QLineEdit::Normal, QString(), false);


      if(num.isEmpty()) {
           gutils->MsgBox("Erreur","Veuillez saisir le num du département.");
      }
      else {
         try {
              int dep_num=num.toInt();
              bool del=this->dep_dao->remove(dep_num);
              if(del) {
              initTableView();
              }
              else {
                  gutils->MsgBox("Echec","Echec de la suppression du département.");
              }
          }
          catch(QException&ex) {
              ex.raise();
          }
      }
}

void DepartementWindow::on_btn_rafraichir_clicked()
{
    this->initTableView();
}

void DepartementWindow::on_btn_rechercher_clicked()
{
    QString num = QInputDialog::getText(this, "Rechercher département", "Entrer le num département:", QLineEdit::Normal, QString(), false);
    int dep_num=num.toInt();
    QGuiUtils*gutils=new QGuiUtils();

    if(num.isEmpty()) {
        gutils->MsgBox("Erreur","Veuillez saisir le numéro département");
    }
    else {
        try {
          departement d=  this->dep_dao->search(dep_num);

          gutils->MsgBox("Info","<b>Nom: </b>"+d.getDDepNom());
          //    this->initTableView();
        }
        catch(QException&ex) {
            ex.raise();
        }
    }
}
