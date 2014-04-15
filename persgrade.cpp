#include "persgrade.h"
#include "ui_persgrade.h"

PersGrade::PersGrade(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PersGrade)
{
    ui->setupUi(this);
}

PersGrade::~PersGrade()
{
    delete ui;
}
