#include "punchout.h"
#include "ui_punchout.h"
#include <QMessageBox>
#include <QDate>
#include <QSqlError>

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

    // 显示是否已签退
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
//    QSqlQuery query;
//    query.prepare("SELECT taskdesc, startdate, enddate, finishdate FROM task where persid = ? and startdate <= curdate() and enddate >= curdate() and finishdate is null");
//    query.addBindValue(persid);
//    query.exec();
//    QString name;
//    while(query.next()){
//        name += query.value(0).toString() + "\n" ;
//    }
//    ui->textBrowser->insertPlainText(name);


    qmodel=new QSqlTableModel();
    qmodel->setTable("task");
    qmodel->removeColumn(1);

    qmodel->setHeaderData(0, Qt::Horizontal, "任务号");
    qmodel->setHeaderData(1, Qt::Horizontal, "任务描述");
    qmodel->setHeaderData(2, Qt::Horizontal, "开始日期");
    qmodel->setHeaderData(3, Qt::Horizontal, "结束日期");
    qmodel->setHeaderData(4, Qt::Horizontal, "完成日期");

    qmodel->setFilter(QObject::tr("persid = '%1'").arg(persid));
    qmodel->setFilter(QObject::tr("finishdate is null"));
    qmodel->setFilter(QObject::tr("startdate <= curdate()"));
    qmodel->setFilter(QObject::tr("enddate >= curdate()"));
    qmodel->select(); //显示结果
    ui->tableView->setModel(qmodel);
}

void PunchOut::on_pushButton_clicked()
{
    qmodel->database().transaction(); //开始事务操作
    if (qmodel->submitAll()) // 提交所有被修改的数据到数据库中
    {
        qmodel->database().commit(); //提交成功，事务将真正修改数据库数据
    } else {
        qmodel->database().rollback(); //提交失败，事务回滚
        QMessageBox::warning(this, tr("错误"),tr("数据库错误: %1").arg(qmodel->lastError().text()));
    }

    QSqlQuery query;
    query.prepare("update punchreg set outtime = curtime() where persid = ? and date = curdate() ");
    query.addBindValue(login_persid);
    query.exec();
    if(query.isActive()){
        QMessageBox::information(this, tr("成功"), tr("添加成功"), QMessageBox::Ok);

    }
}

void PunchOut::on_pushButton_done_clicked()
{
    QDate date;
    qmodel->setData(ui->tableView->currentIndex(), date.currentDate());
}

void PunchOut::on_pushButton_revert_clicked()
{
    qmodel->revertAll(); //撤销修改
    QMessageBox::warning(this, tr("撤销成功"),tr("撤销成功"));
}
