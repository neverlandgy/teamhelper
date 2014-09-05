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


    qmodel=new QSqlTableModel();
    qmodel->setTable("task");
    qmodel->removeColumn(1);

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
    qmodel->database().transaction(); //��ʼ�������
    if (qmodel->submitAll()) // �ύ���б��޸ĵ����ݵ����ݿ���
    {
        qmodel->database().commit(); //�ύ�ɹ������������޸����ݿ�����
    } else {
        qmodel->database().rollback(); //�ύʧ�ܣ�����ع�
        QMessageBox::warning(this, tr("����"),tr("���ݿ����: %1").arg(qmodel->lastError().text()));
    }

    QSqlQuery query;
    query.prepare("update punchreg set outtime = curtime() where persid = ? and date = curdate() ");
    query.addBindValue(login_persid);
    query.exec();
    if(query.isActive()){
        QMessageBox::information(this, tr("�ɹ�"), tr("��ӳɹ�"), QMessageBox::Ok);

    }
}

void PunchOut::on_pushButton_done_clicked()
{
    QDate date;
    qmodel->setData(ui->tableView->currentIndex(), date.currentDate());
}

void PunchOut::on_pushButton_revert_clicked()
{
    qmodel->revertAll(); //�����޸�
    QMessageBox::warning(this, tr("�����ɹ�"),tr("�����ɹ�"));
}
