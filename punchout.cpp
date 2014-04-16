#include "punchout.h"
#include "ui_punchout.h"

PunchOut::PunchOut(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PunchOut)
{
    ui->setupUi(this);

    ui->label_warring->hide();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(UpdateTime()));
    //开启定时器
    timer->start(1000);

    //TODO 显示是否已签退
    QSqlQuery query;
    query.prepare("select count(*) from punchreg where date = curdate() and persid = ? and outtime is not null");
    query.addBindValue(login_persid);
    query.exec();

    if(query.next()){
        if(query.value(0).toInt() != 0){
            ui->pushButton->hide();
            ui->label_warring->show();
        }
    }
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
    query.prepare("update punchreg set outtime = curtime() where persid = ? and date = curdate() ");
    query.addBindValue(login_persid);
    query.exec();
}
