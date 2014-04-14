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

void ProjectGrade::on_pushButton_clicked()
{

}
