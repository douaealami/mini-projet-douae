#include <QtSql>
#include <QString>
#include <QTextStream>
#include <QList>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include "produit.cpp"

class produitdao {
public:

    produitdao() {

    }

    ~produitdao() {}

    bool create(produit*p) {
        QSqlQuery query;
        QString sql="insert into produit values(null,'"+p->getPProdNom()+"','"+p->getPProdDescription()+"',"+QString::number(p->getPProdPrix())+",'"+p->getPProdImage()+"',"+QString::number(p->getCatNum())+")";
        return query.exec(sql);
    }

    bool remove(int prod_num) {
        QSqlQuery query;
        QString sql="delete from produit where prod_num="+QString::number(prod_num);
        return query.exec(sql);
    }

    void list(QTableView*&tv) {
        QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery query;
        QString sql="select * from produit";
        query.prepare(sql);
        query.exec(sql);
        model->setQuery(query);
        tv->setModel(model);
    }

    produit search(int prod_num) {
        QSqlQuery query;
        produit p;
        QString sql="select * from produit where prod_num="+QString::number(prod_num);
        query.prepare(sql);
        query.exec(sql);
        if(query.next()) {
            p.setPProdNum(query.value(0).toInt());
            p.setPProdNom(query.value(1).toString());
            p.setPProdDescription(query.value(2).toString());
            p.setPProdPrix(query.value(3).toInt());
            p.setPProdImage(query.value(4).toString());
            p.setCatNum(query.value(5).toInt());
        }
        return p;
    }
};
