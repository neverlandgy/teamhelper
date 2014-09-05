#include "team.h"
#include "ui_team.h"
#include <QDebug>


Team::Team(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Team)
{
    ui->setupUi(this);

    QSqlQuery query_a;
    query_a.prepare("select persname from pers where persid in (select persid from workreg )");
    query_a.exec();
    while(query_a.next())
    {
        ui->projectB->addItem(query_a.value(0).toString());
    }

    QSqlQuery query_b;
    query_b.prepare("select persname from pers where persid not in (select persid from workreg )");
    query_b.exec();
    while(query_b.next())
    {
        ui->projectA->addItem(query_b.value(0).toString());
    }

}

Team::~Team()
{
    delete ui;
}

void Team::on_leftButton_clicked()
{
    moveCurrentItem(ui->projectB, ui->projectA);
}

void Team::on_rightButton_clicked()
{
    moveCurrentItem(ui->projectA, ui->projectB);
}

void Team::moveCurrentItem(DragListsWidget *source,
                                    DragListsWidget *target)
{
    QSqlQuery query_pers;
    query_pers.prepare("select persid from pers where persname = ?");
    query_pers.addBindValue(source->currentItem()->text());
    query_pers.exec();
    query_pers.next();
    int persid = query_pers.value(0).toInt();

    if (source->currentItem()) {
        if(source == ui->projectB){
            QSqlQuery query;
            query.prepare("insert into workreg values (null, ?, ?)");
            query.addBindValue(1);
            query.addBindValue(persid);
            query.exec();
        }
        else{
            QSqlQuery query;
            query.prepare("delete from workreg where persid = ? and projectid = ? ");
            query.addBindValue(1);
            query.addBindValue(persid);
            query.exec();
        }
//TODO 点击按钮可以插入数据库，还要实现拖动插入数据库
        QListWidgetItem *newItem = source->currentItem()->clone();
        target->addItem(newItem);
        target->setCurrentItem(newItem);
        delete source->currentItem();

    }
}

void Team::on_pushButton_clicked()
{

}
