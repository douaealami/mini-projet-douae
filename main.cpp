#include <QApplication>
#include "windowlogin.h"
#include "dbhelper.cpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    dbhelper*dbh=new dbhelper();

    if(!dbh->connect()) {
    dbh->connect();
     }
    WindowLogin w;
    w.show();

    return a.exec();
}
