#include "salary.h"
#include "ui_salary.h"
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include "salarydialog.h"

Salary::Salary(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Salary)
{
    ui->setupUi(this);

    QSqlQueryModel *qmodel=new QSqlQueryModel();
    qmodel->setQuery("select distinct yearmonth from perssalaryreg ");
    ui->comboBox->setModel(qmodel);
}

Salary::~Salary()
{
    delete ui;
}

void Salary::on_pushButton_clicked()
{
     QString yearmonth;
     yearmonth = ui->comboBox->currentText();

     QSqlTableModel *qmodel1=new QSqlTableModel();
     qmodel1->setTable("perssalaryreg");
     qmodel1->setFilter(QObject::tr("yearmonth = '%1'").arg(yearmonth));
     qmodel1->select(); //ÏÔÊ¾½á¹û
     ui->tableView->setModel(qmodel1);
}

void Salary::on_pushButton_salary_clicked()
{
    SalaryDialog salarydialog;
    salarydialog.exec();
}
