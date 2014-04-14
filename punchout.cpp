#include "punchout.h"
#include "ui_punchout.h"

PunchOut::PunchOut(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PunchOut)
{
    ui->setupUi(this);

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(UpdateTime()));
    //开启定时器
    timer->start(1000);
}

PunchOut::~PunchOut()
{
    delete ui;
}

void PunchOut::UpdateTime()
{
     ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void PunchOut::QueryTask(int persid)
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
//TODO 表格形式显示任务列表，并可以提交完成的任务
}

void PunchOut::on_pushButton_clicked()
{
    QSqlQuery query;
    query.exec("update punchreg set outtime = curtime() where persid = 1 and date = curdate() ");
}
