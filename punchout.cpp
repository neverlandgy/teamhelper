#include "punchout.h"
#include "ui_punchout.h"
#include <QSqlTableModel>

PunchOut::PunchOut(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PunchOut)
{
    ui->setupUi(this);

    ui->label_warring->hide();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(UpdateTime()));
    //������ʱ��
    timer->start(1000);

    // ��ʾ�Ƿ���ǩ��
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
//TODO �����ʽ��ʾ�����б��������ύ��ɵ�����

    QSqlTableModel *qmodel=new QSqlTableModel();
    qmodel->setTable("task");
    qmodel->removeColumn(1);
//    qmodel->removeColumn(4);
    qmodel->setHeaderData(0, Qt::Horizontal, "�����");
    qmodel->setHeaderData(1, Qt::Horizontal, "��������");
    qmodel->setHeaderData(2, Qt::Horizontal, "��ʼ����");
    qmodel->setHeaderData(3, Qt::Horizontal, "��������");
    qmodel->setHeaderData(4, Qt::Horizontal, "�������");

    qmodel->setFilter(QObject::tr("persid = '%1'").arg(persid));
    qmodel->setFilter(QObject::tr("finishdate is null"));
    qmodel->setFilter(QObject::tr("startdate <= curdate()"));
    qmodel->setFilter(QObject::tr("enddate >= curdate()"));
    qmodel->select(); //��ʾ���
    ui->tableView->setModel(qmodel);
}

void PunchOut::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("update punchreg set outtime = curtime() where persid = ? and date = curdate() ");
    query.addBindValue(login_persid);
    query.exec();
}
