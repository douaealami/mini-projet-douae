#ifndef CREERCOMMANDEWINDOW_H
#define CREERCOMMANDEWINDOW_H

#include <QMainWindow>
#include "commandedao.cpp"

namespace Ui {
class creercommandewindow;
}

class creercommandewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit creercommandewindow(QWidget *parent = 0);
    ~creercommandewindow();
    commandedao*cdao=new commandedao();
    commande*c=new commande();

private slots:
    void on_bouton_enregistrer_clicked();

private:
    Ui::creercommandewindow *ui;
};

#endif // CREERCOMMANDEWINDOW_H
