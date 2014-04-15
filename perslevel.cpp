#include "perslevel.h"
#include "ui_perslevel.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>

PersLevel::PersLevel(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PersLevel)
{
    ui->setupUi(this);

    QSqlTableModel *model = new QSqlTableModel;

    model->setTable("pers");
    model->setSort(0, Qt::AscendingOrder);
    model->setHeaderData(0, Qt::Horizontal, "工号");
    model->setHeaderData(1, Qt::Horizontal, "姓名");
    model->setHeaderData(2, Qt::Horizontal, "职务");
    model->setHeaderData(3, Qt::Horizontal, "工作日期");
    model->setHeaderData(4, Qt::Horizontal, "性别");
    model->setHeaderData(5, Qt::Horizontal, "等级");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(3, 150);


//    QTableView *view = new QTableView;
//    view->setModel(model);
//    view->setSelectionMode(QAbstractItemView::SingleSelection);
//    view->setSelectionBehavior(QAbstractItemView::SelectRows);

//    view->resizeColumnsToContents();
//    view->setEditTriggers(QAbstractItemView::NoEditTriggers);

//    QHeaderView *header = view->horizontalHeader();
//    header->setStretchLastSection(true);

//    view->show();
}

PersLevel::~PersLevel()
{
    delete ui;
}

