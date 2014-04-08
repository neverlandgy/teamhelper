#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H

#include <QObject>
#include<QtSql/QtSql>
class SqlConnection : public QObject
{
public:
    SqlConnection();
    bool Connect();
};

#endif // SQLCONNECTION_H
