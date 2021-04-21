#include <QString>
#include <QtSql>

class dbhelper {
public:
    dbhelper(){}
    QSqlDatabase db;
    bool connect() {
        const QString DB_DRIVER="QSQLITE";
        const QString DB_NAME="db_mini-projet.db";
        const QString DB_HOSTNAME="localhost";

        db= QSqlDatabase::addDatabase(DB_DRIVER);
        db.setDatabaseName(DB_NAME);
      //  db.setHostName(DB_HOSTNAME);
        return db.open();
    }

    void close() {
        if(connect()) {
            this->db.close();
            this->db.removeDatabase(QSqlDatabase::defaultConnection);
            qDebug()<<"Connection closed.";
        }
    }
};

