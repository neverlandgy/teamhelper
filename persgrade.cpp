#include "persgrade.h"
#include "ui_persgrade.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>

PersGrade::PersGrade(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PersGrade)
{
    ui->setupUi(this);

    QSqlQueryModel *qmodel=new QSqlQueryModel();
    qmodel->setQuery("select persname from pers ");
    ui->comboBox->setModel(qmodel);
}

PersGrade::~PersGrade()
{
    delete ui;
}

void PersGrade::on_comboBox_currentIndexChanged(const QString &arg1)
{
    leaderappraise = ui->horizontalSlider->value();

    QSqlQuery query;
    query.prepare("select persid from pers where persname = ?");
    query.addBindValue(arg1);
    query.exec();
    query.next();
    persid = query.value(0).toInt();

    QSqlQuery query_joblevel;
    query_joblevel.prepare("select jobtyp, level from pers where persid = ?");
    query_joblevel.addBindValue(persid);
    query_joblevel.exec();
    query_joblevel.next();
    jobtyp = query_joblevel.value(0).toString();
    level = query_joblevel.value(1).toInt();

    QSqlQuery query_notask;
    query_notask.prepare("select count(*) from task where persid = ? and date_format(enddate, '%Y%m') = date_format(curdate(), '%Y%m') and (finishdate > enddate or finishdate is null)");
    query_notask.addBindValue(persid);
    query_notask.exec();
    query_notask.next();
    nofinishtask = query_notask.value(0).toInt();

    QSqlQuery query_task;
    query_task.prepare("select count(*) from task where persid = ? and date_format(enddate, '%Y%m') = date_format(curdate(), '%Y%m')");
    query_task.addBindValue(persid);
    query_task.exec();
    query_task.next();
    task = query_task.value(0).toInt();


    QSqlQuery query_punch;
    query_punch.prepare("select count(*) from punchreg where persid = ? and date_format(date, '%Y%m') = date_format(curdate(), '%Y%m') and timediff(outtime, intime) < '08:00:00' ");
    query_punch.addBindValue(persid);
    query_punch.exec();
    query_punch.next();
    nopunchdate = query_punch.value(0).toInt();

    QSqlQuery query_project;
    query_project.prepare("select avg(grade) from projectgrade where projectid in (select projectid from workreg where persid = ?) and projectid in (select projectid from project where date_format(finishdate, '%Y%m') = date_format(curdate(), '%Y%m') )");
    query_project.addBindValue(persid);
    query_project.exec();
    query_project.next();
    projectgrade = query_project.value(0).toInt();


    ui->label_joblevel->setText(QString::number(level));
    if(task == 0){
        taskgrade = 0;
        ui->label_task->setText(QString::number(taskgrade)+"%");
    }else{
        taskgrade = 100-((nofinishtask*100)/task);
        ui->label_task->setText(QString::number(taskgrade)+"%");
    }
    ui->label_punch->setText(QString::number(nopunchdate));
    ui->label_project->setText(QString::number(projectgrade));
    persgrade = (level*6)+((100-taskgrade)*0.1)-nopunchdate+(projectgrade*0.15)+(leaderappraise*20*0.15);
    ui->lcdNumber->display(persgrade);

}

void PersGrade::on_horizontalSlider_valueChanged()
{
    leaderappraise = ui->horizontalSlider->value();
    persgrade = (level*6)+((100-taskgrade)*0.1)-nopunchdate+(projectgrade*0.15)+(leaderappraise*20*0.15);
    ui->lcdNumber->display(persgrade);
}

void PersGrade::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("insert into persgradereg values(?, date_format(curdate(), '%Y%m'), ?, ?, ?, ?, ?, ?)");
    query.addBindValue(persid);
    query.addBindValue(leaderappraise);
    query.addBindValue(level);
    query.addBindValue(100-taskgrade);
    query.addBindValue(nopunchdate);
    query.addBindValue(projectgrade);
    query.addBindValue(persgrade);
    query.exec();

    QSqlQuery query_salary;
    query_salary.prepare("insert into perssalaryreg (persid, yearmonth, perssalary) values (?, date_format(curdate(), '%Y%m'), ?)");
    query_salary.addBindValue(persid);
    query_salary.addBindValue(persgrade*150);
    query_salary.exec();
}


