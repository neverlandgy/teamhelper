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

//��ʾ������Ϣ
void MainWindow::on_about_action_triggered()
{
    About about;
    about.exec();
}

//�ر�Tabҳǩ
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    index = ui->tabWidget->currentIndex() ;
    ui->tabWidget->removeTab(index);
}

//��ʾ������Ϣҳǩ
void MainWindow::on_myinfo_action_triggered()
{

    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab,"������Ϣ");

    MyInfo *myinfo;
    myinfo = new MyInfo(newTab);
    myinfo->QureyPers();

}

//��ʾǩ��ҳǩ
void MainWindow::on_punchin_action_triggered()
{
    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab,"ǩ��");

    PunchIn *punchin;
    punchin = new PunchIn(newTab);
    punchin->QueryTask(1);

}

//��ʾǩ��ҳǩ
void MainWindow::on_punchout_action_triggered()
{
    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab,"ǩ��");

    PunchOut *punchout;
    punchout = new PunchOut(newTab);
    punchout->QueryTask(1);
}
