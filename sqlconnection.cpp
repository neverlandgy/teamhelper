#include "sqlconnection.h"
#include <QtSql>
#include <QMessageBox>

SqlConnection::SqlConnection()
{

}

bool SqlConnection::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
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
