#include <QtSql>
#include <QString>
#include <QTextStream>
#include <QList>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include "client.cpp"
//#include "dbhelper.cpp"

class clientdao {
public:

    clientdao() {

    }

    ~clientdao() {}

    bool create(client*c) {
        QSqlQuery query;
        QString sql="insert into client values(null,'"+c->getCliNom()+"','"+c->getCliDatenaissance().toString("dd/MM/yyyy")+"','"+c->getCliTel()+"')";
        return query.exec(sql);
       // return query.next();
    }

    bool remove(int cli_num) {
        QSqlQuery query;
        QString sql="delete from client where cli_num="+QString::number(cli_num);
        return query.exec(sql);
    }

    void list(QTableView*&tv) {
        QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery query;
        QString sql="select * from client";
        query.prepare(sql);
        query.exec(sql);
        model->setQuery(query);
        tv->setModel(model);
    }

    client search(int cli_num) {
        QSqlQuery query;
        client c;
        QString sql="select * from client where cli_num="+QString::number(cli_num);;
        query.prepare(sql);
        query.exec(sql);
        if(query.next()) {
            qDebug()<<"cli_nom="<<query.value("cli_nom").toString();
        c.setCliNum(query.value(0).toInt());
        c.setCliNom(query.value(1).toString());
        c.setCliDatenaissance(query.value(2).toDate());
        c.setCliTel(query.value(3).toString());
        }
        return c;
    }
};
