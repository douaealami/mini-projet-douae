#include "windowlogin.h"
#include "ui_windowlogin.h"
#include <QDebug>
#include <QString>
#include <QInputDialog>
#include <QMessageBox>

WindowLogin::WindowLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowLogin)
{
    ui->setupUi(this);

}

WindowLogin::~WindowLogin()
{
    //this->dbh.close();
    delete ui;
}

void WindowLogin::on_pushButton_clicked()
{

    if(ui->txt_username->text().isEmpty() || ui->txt_password->text().isEmpty()) {
        this->gu->MsgBox("Alerte","Veuillez saisir votre login et mot de passe.");
    }
    else {
        this->u->setUusername(ui->txt_username->text());
        this->u->setUPassword(ui->txt_password->text());
    bool login=udao->login(u);

    if(login==true) {
                this->hide();
        this->mw.show();
    }
    else {
        this->gu->MsgBox("Erreur","Username/Password incorrecte.");
    }
    }
 }
