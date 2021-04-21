#include <QtSql>
#include <QString>
#include <QTextStream>
#include <QList>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include "facture.cpp"

class facturedao {
public:
    facturedao() {
    }

    ~facturedao() {}

    bool create(facture*f) {
        QSqlQuery query;
        QString sql=
                "insert into facture(cmd_num,cmd_prod_num,cmd_quantite,cmd_total,cmd_prod_prix) values("+(QString::number(f->getCmdNum()))+","+(QString::number(f->getCmdProdNum()))+","+(QString::number(f->getCmdQuantite()))+","+(QString::number(f->getCmdTotal()))+","+(QString::number(f->getCmdProdPrix()))+")";
        qDebug()<<sql;
        return query.exec(sql);
    }

    bool remove(int fac_num) {
        QSqlQuery query;
        QString sql="delete from facture where fac_num="+QString::number(fac_num);
        return query.exec(sql);
    }

    void list(QTableView*&tv) {
        QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery query;
        QString sql="select * from facture";
        query.prepare(sql);
        query.exec(sql);
        model->setQuery(query);
        tv->setModel(model);
    }

    facture search(int fac_num) {
        QSqlQuery query;
        facture f;
        QString sql="select * from facture where fac_num="+QString::number(fac_num);
        query.prepare(sql);
        query.exec(sql);
        if(query.next()) {
            f.setCmdNum(query.value(1).toInt());
        }
        return f;
    }
};
