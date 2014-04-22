#include "salarydialog.h"
#include "ui_salarydialog.h"

SalaryDialog::SalaryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SalaryDialog)
{
    ui->setupUi(this);
}

SalaryDialog::~SalaryDialog()
{
    delete ui;
}
