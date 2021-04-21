#include <QMessageBox>

class QGuiUtils {
private:


public:
    QGuiUtils(){}
    ~QGuiUtils(){}

    void MsgBox(QString title, QString message) {
        QMessageBox*msg=new QMessageBox();
         msg->setText(message);
         msg->setWindowTitle(title);
         msg->exec();
         msg->show();
    }


};
