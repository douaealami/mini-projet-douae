#include <iostream>
#include <QString>
#include <QDate>

class client {
private:
    int cli_num;
    QString cli_nom;
    QDate cli_datenaissance;
    QString cli_tel;

public:
     client(){}
    ~client(){}

     client(int cli_num, QString cli_nom, QDate cli_datenaissance, QString cli_tel) {
         this->cli_num=cli_num;
         this->cli_nom=cli_nom;
         this->cli_datenaissance=cli_datenaissance;
         this->cli_tel=cli_tel;
     }

     int getCliNum(){
         return this->cli_num;
     }

     QString getCliNom() {
         return this->cli_nom;
     }

     QDate getCliDatenaissance() {
         return this->cli_datenaissance;
     }

     QString getCliTel() {
         return this->cli_tel;
     }

     QString toString() {
         return this->cli_nom+" ("+this->cli_num+")";
     }

     void setCliNum(int cli_num) {
         this->cli_num=cli_num;
     }

     void setCliNom(QString cli_nom) {
         this->cli_nom=cli_nom;
     }

     void setCliDatenaissance(QDate cli_datenaissance) {
         this->cli_datenaissance=cli_datenaissance;
     }

     void setCliTel(QString cli_tel) {
         this->cli_tel=cli_tel;
     }


};
