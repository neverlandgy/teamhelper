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
    querypers.prepare("SELECT persname, jobtypcd, workdate, sex, level FROM pers where persid = 1");
    querypers.exec();
    querypers.next();

//TODO ���Σ����޸ģ���Ҫ����ϸ����Ϣ
    QString name = querypers.value(0).toString();
    QString job = querypers.value(1).toString();
    QDate workdate = querypers.value(2).toDate();
    QString sex = querypers.value(3).toString();
    int level = querypers.value(4).toInt();

    ui->label_6->setText(name);
    ui->label_7->setText(job);
    ui->label_8->setText(workdate.toString());
    ui->label_9->setText(sex);
//    ui->label_10->setText(level);


}
