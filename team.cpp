#include "team.h"
#include "ui_team.h"


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
        ui->projectA->addItem(query_a.value(0).toString());
    }

    QSqlQuery query_b;
    query_b.prepare("select persname from pers where persid not in (select persid from workreg )");
    query_b.exec();
    while(query_b.next())
    {
        ui->projectB->addItem(query_b.value(0).toString());
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
    if (source->currentItem()) {
        QListWidgetItem *newItem = source->currentItem()->clone();
        target->addItem(newItem);
        target->setCurrentItem(newItem);
        delete source->currentItem();
    }
}
