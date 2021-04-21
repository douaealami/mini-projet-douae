#ifndef CREERCATEGORIEWINDOW_H
#define CREERCATEGORIEWINDOW_H

#include <QMainWindow>
#include "categoriedao.cpp"

namespace Ui {
class creercategoriewindow;
}

class creercategoriewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit creercategoriewindow(QWidget *parent = 0);
    ~creercategoriewindow();
    categorie*c=new categorie();
    categoriedao*cdao=new categoriedao();

private slots:
    void on_bouton_enregistrer_clicked();

private:
    Ui::creercategoriewindow *ui;
};

#endif // CREERCATEGORIEWINDOW_H
