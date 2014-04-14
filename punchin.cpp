#include "punchin.h"
#include "ui_punchin.h"

PunchIn::PunchIn(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PunchIn)
{
    ui->setupUi(this);

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(UpdateTime()));
    //开启定时器
    timer->start(1000);

}

PunchIn::~PunchIn()
{
    delete ui;
}

void PunchIn::UpdateTime()
{
     ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void PunchIn::QueryTask(int persid)
{
    QSqlQuery query;
    query.prepare("SELECT taskdesc, startdate, enddate, finishdate FROM task where persid = ? and startdate <= curdate() and enddate >= curdate() and finishdate is null");
    query.addBindValue(persid);
    query.exec();
    QString name;
    while(query.next()){
        name += query.value(0).toString() + "\n" ;
    }
    ui->textBrowser->insertPlainText(name);
//TODO 表格形式显示任务
//TODO 过期任务红色显示
}

void PunchIn::on_pushButton_clicked()
{
    QSqlQuery query;
    query.exec("insert into punchreg (date, persid, intime) values (curdate(), 1, curtime())");
}

//TODO 显示是否已签到
//void PunchIn::QueryPunchReg()
//{
//    QSqlQuery query;
//    query.prepare("select count(*) from punchreg where date = curdate() and persid = 1");
//}
