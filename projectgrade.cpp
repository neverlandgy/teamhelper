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
//TODO δ��ɣ���Ҫ˼����ϸ�Ĵ��ԭ��
void ProjectGrade::on_pushButton_clicked()
{

}
