#include "sqlconnection.h"
#include <QtSql>
#include <QMessageBox>

SqlConnection::SqlConnection()
{

}

//���ݿ�����
bool SqlConnection::Connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");

    /*linux*/
//    db.setDatabaseName("project_DB");
//    db.setUserName("gy");
//    db.setPassword("lma");

    /*windows*/
    db.setDatabaseName("teamhelper");
    db.setUserName("root");
    db.setPassword("lmalma123");

    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                              db.lastError().text());
        return false;
    }
    return true;
}
