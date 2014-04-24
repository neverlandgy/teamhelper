#include "salarydialog.h"
#include "ui_salarydialog.h"
#include <QSqlQueryModel>
#include <QSqlQuery>

SalaryDialog::SalaryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SalaryDialog)
{
    ui->setupUi(this);

    QSqlQueryModel *qmodel=new QSqlQueryModel();
    qmodel->setQuery("select pers.persname, perssalaryreg.perssalary, perssalaryreg.projectbonus, perssalaryreg.festivalbonus from pers, perssalaryreg where pers.persid=perssalaryreg.persid and perssalaryreg.yearmonth = date_format(curdate(), '%Y%m')");
    ui->tableView->setModel(qmodel);

    QSqlQueryModel *qmodel1=new QSqlQueryModel();
    qmodel1->setQuery("select projectname from project where date_format(finishdate, '%Y%m') = date_format(curdate(), '%Y%m')");
    ui->comboBox->setModel(qmodel1);

}

SalaryDialog::~SalaryDialog()
{
    delete ui;
}

void SalaryDialog::on_buttonBox_accepted()
{

}

void SalaryDialog::on_toolBox_currentChanged()
{
    QSqlQueryModel *qmodel=new QSqlQueryModel();
    qmodel->setQuery("select pers.persname, perssalaryreg.perssalary, perssalaryreg.projectbonus, perssalaryreg.festivalbonus from pers, perssalaryreg where pers.persid=perssalaryreg.persid and perssalaryreg.yearmonth = date_format(curdate(), '%Y%m')");
    ui->tableView->setModel(qmodel);
}

void SalaryDialog::on_pushButton_clicked()
{
    int projectbonus;
    QString projectname;
    projectname = ui->comboBox->currentText();

    projectbonus = ui->lineEdit->text().toInt();
    QSqlQuery query;
    query.prepare("update perssalaryreg set projectbonus = ? where persid = (select persid from project, workreg where project.projectname = ? and project.projectid = workreg.projectid)");
    query.addBindValue(projectbonus);
    query.addBindValue(projectname);
    query.exec();
}

void SalaryDialog::on_pushButton_2_clicked()
{
    int festivalbonus;
    festivalbonus = ui->lineEdit_2->text().toInt();
    QSqlQuery query;
    query.prepare("update perssalaryreg set festivalbonus = ? where yearmonth = date_format(curdate(), '%Y%m')");
    query.addBindValue(festivalbonus);
    query.exec();
}
