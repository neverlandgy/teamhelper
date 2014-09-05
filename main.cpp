#include "mainwindow.h"
#include "login.h"
#include "sqlconnection.h"
#include <QApplication>
#include <QtSql>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //编码设置
    QTextCodec *codec = QTextCodec::codecForName("GB2312");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    //连接数据库并判断是否连接成功
    SqlConnection sql;
    if(!sql.Connect())
    {
        return app.exec();
    }
    Login log;
    log.exec();

    if(login_singal == 0){
        return app.exec();
    }
    MainWindow win;
    win.show();

    return app.exec();
}
