#include "task.h"
#include "ui_task.h"

Task::Task(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);

    QSqlQueryModel *qmodel=new QSqlQueryModel();
    qmodel->setQuery("select persname from pers ");
    ui->comboBox->setModel(qmodel);

//    �趨���ڿؼ���ʾ��ǰ����
    ui->dateEdit_start->setDate(QDate::currentDate());
    ui->dateEdit_start->setMinimumDate(QDate::currentDate());
    ui->dateEdit_end->setDate(QDate::currentDate());
}

Task::~Task()
{
    delete ui;
}

//��֤�������ڴ�����ʼ����
void Task::on_dateEdit_start_dateChanged()
{
    ui->dateEdit_end->setMinimumDate(ui->dateEdit_start->date());
}


void Task::on_pushButton_clicked()
{
    QString persname, task;
    QDate startdate, enddate;

    persname = ui->comboBox->currentText();
    startdate = ui->dateEdit_start->date();
    enddate = ui->dateEdit_end->date();
    task = ui->textEdit->toPlainText();

    QSqlQuery query;
    query.prepare("insert into task (persid, taskdesc, startdate, enddate) values ((select persid from pers where persname = ?), ?, ?, ?)");
    query.addBindValue(persname);
    query.addBindValue(task);
    query.addBindValue(startdate);
    query.addBindValue(enddate);

    query.exec();
    if(query.isActive()){
        QMessageBox::information(this, tr("�ɹ�"), tr("��ӳɹ�"), QMessageBox::Ok);

    }
}
