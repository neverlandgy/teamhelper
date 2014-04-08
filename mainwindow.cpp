#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "myinfo.h"

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

//显示个人信息
void MainWindow::on_myinfo_action_triggered()
{

    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab,"个人信息");

    MyInfo *myinfo;
    myinfo = new MyInfo(newTab);
    myinfo->QureyPers();

}

//关闭页签
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    index = ui->tabWidget->currentIndex() ;
    ui->tabWidget->removeTab(index);
}
