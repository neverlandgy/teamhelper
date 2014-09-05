#include "myinfo.h"
#include "ui_myinfo.h"



MyInfo::MyInfo(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MyInfo)
{
    ui->setupUi(this);
}

MyInfo::~MyInfo()
{
    delete ui;
}

void MyInfo::QureyPers()
{
    QSqlQuery querypers;
    querypers.prepare("SELECT p.persname, p.jobtyp, p.workdate, p.sex, p.level, r.persgrade, max(r.yearmonth) month FROM pers as p, persgradereg as r where p.persid = ? and p.persid = r.persid;");
    querypers.addBindValue(login_persid);
    querypers.exec();
    querypers.next();

//TODO 雏形，待修改，需要更详细的信息
    QString name = querypers.value(0).toString();
    QString job = querypers.value(1).toString();
    QString workdate = querypers.value(2).toString();
    QString sex = querypers.value(3).toString();
    QString level = querypers.value(4).toString();
    QString grade = querypers.value(5).toString();

    ui->label_6->setText(name);
    ui->label_7->setText(job);
    ui->label_8->setText(workdate);
    ui->label_9->setText(sex);
    ui->label_10->setText(level);
    ui->label_12->setText(grade);

}
