#include <QString>
class categorie {
private:
    int cat_num;
    QString cat_nom;
    int dep_num;

public:
    categorie() {}
    ~categorie() {}

    categorie(int cat_num, QString cat_nom, int dep_num) {
        this->cat_num=cat_num;
        this->cat_nom=cat_nom;
        this->dep_num=dep_num;
    }

    int getCatNum() { return this->cat_num;}
    QString getCatNom(){return this->cat_nom;}
    int getDepNum() { return this->dep_num;}

    void setCatNum(int cat_num) {
        this->cat_num=cat_num;
    }
    void setCatNom(QString cat_nom) {
        this->cat_nom=cat_nom;
    }

    void setDepNum(int dep_num) {
        this->dep_num=dep_num;
    }

    QString toString() {
        return "categorie_nom= "+this->cat_nom;
    }
};
