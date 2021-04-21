#include <QtSql>
#include <QString>
#include <QTextStream>
#include <QList>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include "categorie.cpp"

class categoriedao {
public:
    categoriedao() {
    }

    ~categoriedao() {}

    bool create(categorie*c) {
        QSqlQuery query;
        QString sql="insert into categorie(cat_nom,dep_num) values('"+c->getCatNom()+"',"+QString::number(c->getDepNum())+")";
        qDebug()<<sql;
        return query.exec(sql);
    }

    bool remove(int c_cat_num) {
        QSqlQuery query;
        QString sql="delete from categorie where cat_num="+QString::number(c_cat_num);
        return query.exec(sql);
    }

    void list(QTableView*&tv) {
        QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery query;
        QString sql="select * from categorie";
        query.prepare(sql);
        query.exec(sql);
        model->setQuery(query);
        tv->setModel(model);
    }

    categorie search(int cat_num) {
        QSqlQuery query;
        categorie c;
        QString sql="select * from categorie where cat_num="+QString::number(cat_num);
        query.prepare(sql);
        query.exec(sql);
        if(query.next()) {
        c.setCatNum(query.value(0).toInt());
        c.setCatNom(query.value(1).toString());
        c.setDepNum(query.value(2).toInt());
        }
        return c;
    }
};
