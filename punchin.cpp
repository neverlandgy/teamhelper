#include "punchin.h"
#include "ui_punchin.h"
#include <QDebug>
#include <QSqlTableModel>

PunchIn::PunchIn(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PunchIn)
{
    ui->setupUi(this);

    ui->label_warring->hide();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(UpdateTime()));
    //开启定时器
    timer->start(1000);

    // 显示是否已签到
    QSqlQuery query;
    query.prepare("select count(*) from punchreg where date = curdate() and persid = ?");
    query.addBindValue(login_persid);
    query.exec();

    if(query.next()){
        if(query.value(0).toInt() != 0){
            ui->pushButton->hide();
            ui->label_warring->show();
        }
    }
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
//    QSqlQuery query;
//    query.prepare("SELECT taskdesc, startdate, enddate, finishdate FROM task where persid = ? and startdate <= curdate() and enddate >= curdate() and finishdate is null");
//    query.addBindValue(persid);
//    query.exec();
//    QString name;
//    while(query.next()){
//        name += query.value(0).toString() + "\n" ;
//    }
//    ui->textBrowser->insertPlainText(name);
//TODO 表格形式显示任务
//TODO 过期任务红色显示
    QSqlTableModel *qmodel=new QSqlTableModel();
    qmodel->setTable("task");
    qmodel->removeColumn(1);
    qmodel->removeColumn(4);
    qmodel->setHeaderData(0, Qt::Horizontal, "任务号");
    qmodel->setHeaderData(1, Qt::Horizontal, "任务描述");
    qmodel->setHeaderData(2, Qt::Horizontal, "开始日期");
    qmodel->setHeaderData(3, Qt::Horizontal, "结束日期");
    qmodel->setFilter(QObject::tr("persid = '%1'").arg(persid));
    qmodel->setFilter(QObject::tr("finishdate is null"));
    qmodel->setFilter(QObject::tr("startdate <= curdate()"));
    qmodel->setFilter(QObject::tr("enddate >= curdate()"));
    qmodel->select(); //显示结果
    ui->tableView->setModel(qmodel);
}

void PunchIn::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("insert into punchreg (date, persid, intime) values (curdate(), ?, curtime())");
    query.addBindValue(login_persid);
    query.exec();
}



