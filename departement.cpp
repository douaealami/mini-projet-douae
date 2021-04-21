#include <QString>
class departement {
private:
    int d_dep_num;
    QString d_dep_nom;

public:
    departement(){}
    ~departement(){}
    departement(int d_dep_num, QString d_dep_nom) {
        this->d_dep_num=d_dep_num;
        this->d_dep_nom;
    }

    int getDDepNum() {
        return this->d_dep_num;
    }

    QString getDDepNom() {
        return this->d_dep_nom;
    }

    void setDDepNum(int d_dep_num) {
        this->d_dep_num=d_dep_num;
    }

    void setDDepNom(QString d_dep_nom) {
        this->d_dep_nom=d_dep_nom;
    }

    QString toString() {
        return "departement_nom= "+getDDepNom();
    }
};
