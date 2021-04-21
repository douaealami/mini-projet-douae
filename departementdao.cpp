#include <QtSql>
#include <QString>
#include <QTextStream>
#include <QList>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include "departement.cpp"
//#include "dbhelper.cpp"

class departementdao {
public:

    departementdao() {
       /* dbhelper*dbh=new dbhelper();

        if(!dbh->connect()) {
        dbh->connect();
         }*/
    }

    ~departementdao() {}

    bool create(departement*d) {
        QSqlQuery query;
        QString sql="insert into departement values(null,'"+d->getDDepNom()+"')";
        return query.exec(sql);
    }

    bool remove(int d_dep_num) {
        QSqlQuery query;
        QString sql="delete from departement where dep_num="+QString::number(d_dep_num);
        query.prepare(sql);
        return query.exec(sql);
    }

    void list(QTableView*&tv) {
        QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery query;
        QString sql="select * from departement";
        query.prepare(sql);
        query.exec(sql);
        model->setQuery(query);
        tv->setModel(model);

    }

    departement search(int dep_num) {
        QSqlQuery query;
        departement dep;
        QString sql="select * from departement where dep_num="+QString::number(dep_num);
        query.prepare(sql);
        query.exec(sql);
        if(query.next()) {
        dep.setDDepNum(query.value(0).toInt());
        dep.setDDepNom(query.value(1).toString());
        }
        return dep;
    }
};
