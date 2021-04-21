#include <QtSql>
#include <QString>
#include <QTextStream>
#include <QList>
#include <QDebug>
#include "utilisateur.cpp"
//#include "dbhelper.cpp"

class utilisateurdao {
public:

    utilisateurdao() {
       /* dbhelper*dbh=new dbhelper();

        if(!dbh->connect()) {
        dbh->connect();
         }*/
    }

    ~utilisateurdao() {}

    bool login(utilisateur*u) {
        QSqlQuery query;
        QString sql="select * from utilisateur where u_username='"+u->getUusername()+"' and u_password='"+u->getUPassword()+"'";
        query.exec(sql);
        //query.value(0).toString() ==> username
        return query.next();
    }
};
