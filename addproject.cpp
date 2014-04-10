#include "addproject.h"
#include "ui_addproject.h"
#include <QMessageBox>

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

}

void AddProject::on_commit_clicked()
{
    QString project, leaderid, describe;
    project = ui->lineEdit_projectname->text();
    leaderid = ui->comboBox_leader->currentText();
    describe = ui->plainTextEdit_desc->toPlainText();
    if(ui->lineEdit_projectname->text().isEmpty()){
         QMessageBox::information(this, tr("错误"), tr("请重新输入"), QMessageBox::Ok);
    }
    QSqlQuery query;
    query.prepare("insert into project (projectname, leaderid, projectdesc) values (?, ?, ?)");
    query.addBindValue(project);
    query.addBindValue(leaderid);
    query.addBindValue(describe);
    query.exec();

    //BUG 未传入值
}
