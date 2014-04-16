#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    ui->tabWidget->addTab(newTab, "������Ϣ");


    MyInfo *myinfo;
    myinfo = new MyInfo(newTab);
    myinfo->QureyPers();

    ui->tabWidget->setCurrentWidget(newTab);
}

//��ʾǩ��ҳǩ
void MainWindow::on_punchin_action_triggered()
{
    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab, "ǩ��");

    PunchIn *punchin;
    punchin = new PunchIn(newTab);
    punchin->QueryTask(login_persid);

    ui->tabWidget->setCurrentWidget(newTab);
}

//��ʾǩ��ҳǩ
void MainWindow::on_punchout_action_triggered()
{
    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab, "ǩ��");

    PunchOut *punchout;
    punchout = new PunchOut(newTab);
    punchout->QueryTask(login_persid);

    ui->tabWidget->setCurrentWidget(newTab);
}

//��ʾ������Ŀҳǩ
void MainWindow::on_addproject_action_triggered()
{
    if(login_mode == "����"){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "������Ŀ");

        AddProject *addproject;
        addproject = new AddProject(newTab);

        ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ�ù���ģʽ��¼"), QMessageBox::Ok);
    }
}

//��ʾ��Ŀ�Ŷ�ҳǩ
void MainWindow::on_team_action_triggered()
{
    if(login_mode == "����" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "������Ŀ");

        Team *team;
        team = new Team(newTab);

        ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ�ù���ģʽ��¼"), QMessageBox::Ok);
    }
}


//��ʾ��Ŀ���ҳǩ
void MainWindow::on_teamgrade_action_triggered()
{
    if(login_mode == "����" ){
    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab, "��Ŀ���");

    ProjectGrade *projectgrade;
    projectgrade = new ProjectGrade(newTab);

    ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ�ù���ģʽ��¼"), QMessageBox::Ok);
    }
}

//��ʾԱ������ҳǩ
void MainWindow::on_perslevel_action_triggered()
{
    if(login_mode == "����" ){
    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab, "Ա������");

    PersLevel *perslevel;
    perslevel = new PersLevel(newTab);

    ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ�ù���ģʽ��¼"), QMessageBox::Ok);
    }
}

//��ʾԱ�����ҳǩ
void MainWindow::on_persgrade_action_triggered()
{
    if(login_mode == "����" ){
    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab, "Ա�����");

    PersGrade *persgrade;
    persgrade = new PersGrade(newTab);

    ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ�ù���ģʽ��¼"), QMessageBox::Ok);
    }
}

//��ʾ�������ҳǩ
void MainWindow::on_task_action_triggered()
{
    if(login_mode == "����" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "Ա�����");

        Task *task;
        task = new Task(newTab);

        ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ�ù���ģʽ��¼"), QMessageBox::Ok);
    }
}

//��ʾ���ʷ���ҳǩ
void MainWindow::on_salary_action_triggered()
{
    if(login_mode == "����" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "���ʷ���");

        Salary *salary;
        salary = new Salary(newTab);

        ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ�ù���ģʽ��¼"), QMessageBox::Ok);
    }
}
