#include "task.h"
#include "ui_task.h"

Task::Task(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
}

Task::~Task()
{
    delete ui;
}
