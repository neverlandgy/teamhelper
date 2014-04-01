#include "mainwindow.h"
#include "login.h"
#include "sqlconnection.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    SqlConnection sql;
    if(!sql.connect())
    {
        return app.exec();
    }
    Login log;
    log.exec();
    MainWindow win;
    win.show();

    return app.exec();
}
