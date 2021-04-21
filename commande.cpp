#include <QDate>
#include <QString>
class commande {
private:
    int cmd_num;
    QDate cmd_date;
    QString cmd_statut;
    int cli_num;

public:
    commande(){}
    ~commande(){}
    commande(int cmd_num, QDate cmd_date, QString cmd_statut, int cli_num) {
        this->cmd_num=cmd_num;
        this->cmd_date=cmd_date;
        this->cmd_statut=cmd_statut;
        this->cli_num=cli_num;
    }

    int getCmdNum() { return this->cmd_num;}
    QDate getCmdDate() { return this->cmd_date;}
    QString getCmdStatut() { return this->cmd_statut;}
    int getCliNum() { return this->cli_num;}

    void setCmdNum(int cmd_num) { this->cmd_num=cmd_num;}
    void setCmdDate(QDate cmd_date) { this->cmd_date=cmd_date;}
    void setCmdStatut(QString cmd_statut) { this->cmd_statut=cmd_statut;}
    void setCliNum(int cli_num) { this->cli_num=cli_num;}
};
