#include "salary.h"
#include "ui_salary.h"

Salary::Salary(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Salary)
{
    ui->setupUi(this);
}

Salary::~Salary()
{
    delete ui;
}
