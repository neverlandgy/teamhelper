#include "addproject.h"
#include "ui_addproject.h"
#include <QMessageBox>
#include <QSqlQueryModel>

AddProject::AddProject(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AddProject)
{
    ui->setupUi(this);
    QSqlQueryModel *qmodel=new QSqlQueryModel();
    qmodel->setQuery("select persname from pers where jobtyp = '项目经理'");
    ui->comboBox_leader->setModel(qmodel);
}

AddProject::~AddProject()
{
    delete ui;
}

void AddProject::on_commit_clicked()
{
    QString project, leadername, describe;
    project = ui->lineEdit_projectname->text();
    leadername = ui->comboBox_leader->currentText();
    describe = ui->plainTextEdit_desc->toPlainText();

    QSqlQuery querypers;
    querypers.prepare("SELECT persid FROM pers where persname = ?");
    querypers.addBindValue(leadername);
    querypers.exec();
    querypers.next();
    int leaderid = querypers.value(0).toInt();

    if(ui->lineEdit_projectname->text().isEmpty()){
         QMessageBox::information(this, tr("错误"), tr("请重新输入"), QMessageBox::Ok);
    }
    QSqlQuery query;
    query.prepare("insert into project (projectname, leaderid, projectdesc) values (?, ?, ?)");
    query.addBindValue(project);
    query.addBindValue(leaderid);
    query.addBindValue(describe);
    query.exec();
    if(query.isActive()){
        QMessageBox::information(this, tr("成功"), tr("添加成功"), QMessageBox::Ok);

    }
}
