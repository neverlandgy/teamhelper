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

//��ʾ������Ϣ
void MainWindow::on_about_action_triggered()
{
    About about;
    about.exec();
}

//��ʾ������Ϣ
void MainWindow::on_myinfo_action_triggered()
{

    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab,"������Ϣ");

    MyInfo *myinfo;
    myinfo = new MyInfo(newTab);
    myinfo->QureyPers();

}

//�ر�ҳǩ
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    index = ui->tabWidget->currentIndex() ;
    ui->tabWidget->removeTab(index);
}
