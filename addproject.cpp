#include "addproject.h"
#include "ui_addproject.h"

AddProject::AddProject(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AddProject)
{
    ui->setupUi(this);
}

AddProject::~AddProject()
{
    delete ui;
}

void AddProject::commit()
{
    QString project, leaderid, describe;
    project = ui->lineEdit_projectname->text();
    leaderid = ui->comboBox_leader->currentText();
    describe = ui->plainTextEdit_desc->toPlainText();
    QSqlQuery query;
    query.prepare("insert into project (projectname, leaderid, projectdesc) values (?, ?, ?)");
    query.addBindValue(project);
    query.addBindValue(leaderid);
    query.addBindValue(describe);
    query.exec();

}

void AddProject::on_commit_clicked()
{
     AddProject addproject;
     addproject.commit();
}
