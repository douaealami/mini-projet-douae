#include <QtSql>
#include <QString>
#include <QTextStream>
#include <QList>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include "commande.cpp"

class commandedao {
public:

    commandedao() {

    }

    ~commandedao() {}

    bool create(commande*c) {
        QSqlQuery query;
        QString sql="insert into commande values(null,'"+c->getCmdDate().toString("dd/MM/yyyy")+"','"+c->getCmdStatut()+"',"+QString::number(c->getCliNum())+")";
        return query.exec(sql);
    }

    bool remove(int cmd_num) {
        QSqlQuery query;
        QString sql="delete from commande where cmd_num="+QString::number(cmd_num);
        return query.exec(sql);
    }

    void list(QTableView*&tv) {
        QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery query;
        QString sql="select * from commande";
        query.prepare(sql);
        query.exec(sql);
        model->setQuery(query);
        tv->setModel(model);
    }

    commande search(int cmd_num) {
        QSqlQuery query;
        commande c;
        QString sql="select * from commande where cmd_num="+QString::number(cmd_num);
        query.prepare(sql);
        query.exec(sql);
        if(query.next()) {
        c.setCmdNum(query.value(0).toInt());
        c.setCmdDate(query.value(1).toDate());
        c.setCmdStatut(query.value(2).toString());
        c.setCliNum(query.value(3).toInt());
        }
        return c;
    }
};
