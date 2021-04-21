#include <iostream>
#include <QString>

using namespace std;
class utilisateur {
private:
    int u_id;
    QString u_username;
    QString u_password;

public:
    utilisateur(){}
    ~utilisateur() {}

    int getUId() {
        return this->u_id;
    }

    QString getUusername() {
        return this->u_username;
    }

    QString getUPassword() {
        return this->u_password;
    }

    QString toString() {
        return this->u_username+" ("+this->u_id+")";
    }

    void setUId(int u_id) {
        this->u_id=u_id;
    }

    void setUusername(QString u_username) {
        this->u_username=u_username;
    }

    void setUPassword(QString u_password) {
        this->u_password=u_password;
    }
};
