class facture {
private:
    int fac_num;
    int cmd_num;
    int cmd_prod_num;
    int cmd_quantite;
    int cmd_total;
    int cmd_prod_prix;

public:
    facture(){}
    ~facture(){}
    facture(int fac_num, int cmd_num, int cmd_prod_num,int cmd_quantite, int cmd_total, int cmd_prod_prix) {
        this->fac_num=fac_num;
        this->cmd_num=cmd_num;
        this->cmd_prod_num=cmd_prod_num;
        this->cmd_quantite=cmd_quantite;
        this->cmd_total=cmd_total;
        this->cmd_prod_prix=cmd_prod_prix;
    }

    int getFacNum() { return this->fac_num;}
    int getCmdNum() { return this->cmd_num;}
    int getCmdProdNum() { return this->cmd_prod_num;}
    int getCmdQuantite() { return this->cmd_quantite;}
    int getCmdTotal() { return this->cmd_total;}
    int getCmdProdPrix() { return this->cmd_prod_prix;}

    void setFacNum(int fac_num) {  this->fac_num=fac_num;}
    void setCmdNum(int cmd_num) {  this->cmd_num=cmd_num;}
    void setCmdProdNum(int cmd_prod_num) {  this->cmd_prod_num=cmd_prod_num;}
    void setCmdQuantite(int cmd_quantite) {  this->cmd_quantite=cmd_quantite;}
    void setCmdTotal(int cmd_total) {  this->cmd_total=cmd_total;}
    void setCmdProdPrix(int cmd_prod_prix) {  this->cmd_prod_prix=cmd_prod_prix;}

};
