#include "creerclientwindow.h"
#include "ui_creerclientwindow.h"
#include "qguiutils.cpp"

CreerClientWindow::CreerClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreerClientWindow)
{
    ui->setupUi(this);
}

CreerClientWindow::~CreerClientWindow()
{
    delete ui;
}

void CreerClientWindow::on_bouton_enregistrer_clicked()
{
    QGuiUtils*gu=new QGuiUtils();
    if(this->ui->txt_nom->text().isEmpty() || this->ui->txt_telephone->text().isEmpty()) {
        gu->MsgBox("Alerte","Please fill in the blanks");
    }
    else {
        this->c->setCliNom(ui->txt_nom->text());
        this->c->setCliDatenaissance(ui->date_naissance->date());
        this->c->setCliTel(ui->txt_telephone->text());
        bool create=this->cdao->create(c);


        if(create) {
            gu->MsgBox("Success","Successfully created client.");
        }
        else {
            gu->MsgBox("Error","Failed TO create client. Please retry later.");
        }

    }
}
