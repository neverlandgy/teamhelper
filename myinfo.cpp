#include "myinfo.h"
#include "ui_myinfo.h"
#include <QDate>
#include <QSqlQuery>
#include <QMessageBox>

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

    QString name = querypers.value(0).toString();
    QString job = querypers.value(1).toString();
    QDate workdate = querypers.value(2).toDate();
    QString sex = querypers.value(3).toString();
    int level = querypers.value(4).toInt();
    QMessageBox::about(NULL,name,job);

    ui->label_6->setText(name);
    ui->label_7->setText(job);
    //ui->label_8->setText(workdate);
    ui->label_9->setText(sex);
    //ui->label_10->setText(level);


}
