#include "perslevel.h"
#include "ui_perslevel.h"

PersLevel::PersLevel(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PersLevel)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);

    model->setTable("pers");
    model->setSort(0, Qt::AscendingOrder);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(0, Qt::Horizontal, "工号");
    model->setHeaderData(1, Qt::Horizontal, "姓名");
    model->setHeaderData(2, Qt::Horizontal, "职务");
    model->setHeaderData(3, Qt::Horizontal, "工作日期");
    model->setHeaderData(4, Qt::Horizontal, "性别");
    model->setHeaderData(5, Qt::Horizontal, "等级");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(3, 150);
}

PersLevel::~PersLevel()
{
    delete ui;
}

void PersLevel::on_pushButton_commit_clicked()
{
    model->database().transaction(); //开始事务操作
    if (model->submitAll()) // 提交所有被修改的数据到数据库中
    {
        model->database().commit(); //提交成功，事务将真正修改数据库数据
    } else {
        model->database().rollback(); //提交失败，事务回滚
        QMessageBox::warning(this, tr("错误"),tr("数据库错误: %1").arg(model->lastError().text()));
    }
}



void PersLevel::on_pushButton_delete_clicked()
{
    int curRow = ui->tableView->currentIndex().row();     //获取选中的行
    model->removeRow(curRow);     //删除该行
    int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定删除当前行吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        model->revertAll(); //如果不删除，则撤销
    }else {
        model->submitAll(); //否则提交，在数据库中删除该行
    }
}

void PersLevel::on_pushButton_add_clicked()
{
    int rowNum = model->rowCount(); //获得表的行数
    int persid = model->rowCount()+1;
    model->insertRow(rowNum); //添加一行
    model->setData(model->index(rowNum,0),persid);
    //model->submitAll(); //可以直接提交
}

void PersLevel::on_pushButton_revert_clicked()
{
    model->revertAll(); //撤销修改
    QMessageBox::warning(this, tr("撤销成功"),tr("撤销成功"));

}
