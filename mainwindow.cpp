#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "myinfo.h"
#include "punchin.h"
#include "punchout.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//显示关于信息
void MainWindow::on_about_action_triggered()
{
    About about;
    about.exec();
}

//关闭Tab页签
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    index = ui->tabWidget->currentIndex() ;
    ui->tabWidget->removeTab(index);
}

//显示个人信息页签
void MainWindow::on_myinfo_action_triggered()
{

    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab,"个人信息");

    MyInfo *myinfo;
    myinfo = new MyInfo(newTab);
    myinfo->QureyPers();

}

//显示签到页签
void MainWindow::on_punchin_action_triggered()
{
    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab,"签到");

    PunchIn *punchin;
    punchin = new PunchIn(newTab);
    punchin->QueryTask(1);

}

//显示签退页签
void MainWindow::on_punchout_action_triggered()
{
    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab,"签退");

    PunchOut *punchout;
    punchout = new PunchOut(newTab);
    punchout->QueryTask(1);
}
