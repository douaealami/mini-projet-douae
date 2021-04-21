#ifndef CREERFACTUREWINDOW_H
#define CREERFACTUREWINDOW_H

#include <QMainWindow>
#include "facturedao.cpp"

namespace Ui {
class creerfacturewindow;
}

class creerfacturewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit creerfacturewindow(QWidget *parent = 0);
    ~creerfacturewindow();
    facturedao*fdao=new facturedao();
    facture*f=new facture();

private slots:
    void on_bouton_enregistrer_clicked();

private:
    Ui::creerfacturewindow *ui;
};

#endif // CREERFACTUREWINDOW_H
