#include "projectgrade.h"
#include "ui_projectgrade.h"


ProjectGrade::ProjectGrade(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ProjectGrade)
{
    ui->setupUi(this);

    QSqlQueryModel *qmodel=new QSqlQueryModel();
    qmodel->setQuery("select projectname from project where finishdate is null");
    ui->comboBox->setModel(qmodel);
}

ProjectGrade::~ProjectGrade()
{
    delete ui;
}

void ProjectGrade::on_pushButton_clicked()
{
    projectname = ui->comboBox->currentText();
    diff = ui->horizontalSlider_Diff->value();
    benefit = ui->horizontalSlider_Benefit->value();
    time = ui->horizontalSlider_Time->value();
    report = ui->horizontalSlider_Report->value();
    review = ui->horizontalSlider_Review->value();

    grade = 4 * (diff + benefit + time + report + review);

    QSqlQuery query;
    query.prepare("insert into projectgrade (projectid, diff, benefit, time, report, review, grade) values ((select projectid from project where projectname = ? ), ?, ?, ? ,? , ?, ?)");
    query.addBindValue(projectname);
    query.addBindValue(diff);
    query.addBindValue(benefit);
    query.addBindValue(time);
    query.addBindValue(report);
    query.addBindValue(review);
    query.addBindValue(grade);
    query.exec();

    QSqlQuery query1;
    query1.prepare("update project set finishdate = curdate() where projectname = ?");
    query1.addBindValue(projectname);
    query1.exec();
}

void ProjectGrade::on_horizontalSlider_Diff_valueChanged()
{
    setLcdNumber();
}

void ProjectGrade::on_horizontalSlider_Benefit_valueChanged()
{
    setLcdNumber();
}

void ProjectGrade::on_horizontalSlider_Time_valueChanged()
{
    setLcdNumber();
}

void ProjectGrade::on_horizontalSlider_Report_valueChanged()
{
    setLcdNumber();
}

void ProjectGrade::on_horizontalSlider_Review_valueChanged()
{
    setLcdNumber();
}

void ProjectGrade::setLcdNumber()
{
    diff = ui->horizontalSlider_Diff->value();
    benefit = ui->horizontalSlider_Benefit->value();
    time = ui->horizontalSlider_Time->value();
    report = ui->horizontalSlider_Report->value();
    review = ui->horizontalSlider_Review->value();
    grade = 4 * (diff + benefit + time + report + review);

    QPalette lcdp = ui->lcdNumber->palette();

    if(grade<=20){
        lcdp.setColor(QPalette::Normal, QPalette::WindowText, QColor(155, 0, 0, 255));
    }else if(20<grade && grade<=40){
        lcdp.setColor(QPalette::Normal, QPalette::WindowText, QColor(180, 0, 0, 255));
    }else if(40<grade && grade<=60){
        lcdp.setColor(QPalette::Normal, QPalette::WindowText, QColor(205, 0, 0, 255));
    }else if(60<grade && grade<=80){
        lcdp.setColor(QPalette::Normal, QPalette::WindowText, QColor(230, 0, 0, 255));
    }else if(80<grade && grade<=100){
        lcdp.setColor(QPalette::Normal, QPalette::WindowText, QColor(255, 0, 0, 255));
    }
    ui->lcdNumber->setPalette(lcdp);
    ui->lcdNumber->display(grade);
}
