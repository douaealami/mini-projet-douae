#include <QString>
class produit {
private:
    int p_prod_num;
    QString p_prod_nom;
    QString p_prod_description;
    int p_prod_prix;
    QString p_prod_image;
    int cat_num;

public:
    produit() {}
    ~produit() {}
    produit(int p_prod_num, QString p_prod_nom, QString p_prod_description, int p_prod_prix, QString p_prod_image, int cat_num) {
        this->p_prod_num=p_prod_num;
        this->p_prod_nom=p_prod_nom;
        this->p_prod_description=p_prod_description;
        this->p_prod_prix=p_prod_prix;
        this->p_prod_image=p_prod_image;
        this->cat_num=cat_num;
    }

    int getPProdNum() {return this->p_prod_num;}
    QString getPProdNom() {return this->p_prod_nom;}
    QString getPProdDescription() {return this->p_prod_description;}
    int getPProdPrix() {return this->p_prod_prix;}
    QString getPProdImage() {return this->p_prod_image;}
    int getCatNum() { return this->cat_num;}

    void setPProdNum(int p_prod_num) { this->p_prod_num=p_prod_num;}
    void setPProdNom(QString p_prod_nom) { this->p_prod_nom=p_prod_nom;}
    void setPProdDescription(QString p_prod_description) {this->p_prod_description=p_prod_description;}
    void setPProdPrix(int p_prod_prix) {this->p_prod_prix=p_prod_prix;}
    void setPProdImage(QString p_prod_image) { this->p_prod_image=p_prod_image;}
    void setCatNum(int cat_num) {this->cat_num=cat_num;}


};
