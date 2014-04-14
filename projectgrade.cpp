#include "projectgrade.h"
#include "ui_projectgrade.h"

ProjectGrade::ProjectGrade(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ProjectGrade)
{
    ui->setupUi(this);
}

ProjectGrade::~ProjectGrade()
{
    delete ui;
}
//TODO 未完成，需要思考详细的打分原则
void ProjectGrade::on_pushButton_clicked()
{

}
