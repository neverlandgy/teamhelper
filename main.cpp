#include "mainwindow.h"
#include "login.h"
#include "sqlconnection.h"
#include <QApplication>
#include <QtSql>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //��������
    QTextCodec *codec = QTextCodec::codecForName("GB2312");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    //�������ݿⲢ�ж��Ƿ����ӳɹ�
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
