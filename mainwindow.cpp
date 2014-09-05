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
    if(login_mode != "����" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "������Ϣ");
        MyInfo *myinfo;
        myinfo = new MyInfo(newTab);

        QGridLayout *gridLayout_tab;
        gridLayout_tab = new QGridLayout(newTab);
        gridLayout_tab->setSpacing(6);
        gridLayout_tab->setContentsMargins(11, 11, 11, 11);
        gridLayout_tab->setObjectName(QString::fromUtf8("gridLayout_tab"));

        QSpacerItem *verticalSpacer;
        QSpacerItem *horizontalSpacer_2;
        QSpacerItem *horizontalSpacer;
        QSpacerItem *verticalSpacer_2;
        gridLayout_tab->addWidget(myinfo, 2, 1, 1, 1);
        verticalSpacer = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer, 0, 1, 1, 1);
        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer_2, 2, 2, 1, 1);
        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer, 2, 0, 1, 1);
        verticalSpacer_2 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer_2, 3, 1, 1, 1);
        myinfo->QureyPers();

        ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ������ģʽ��¼"), QMessageBox::Ok);
    }
}

//��ʾǩ��ҳǩ
void MainWindow::on_punchin_action_triggered()
{
    if(login_mode != "����" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "ǩ��");

        PunchIn *punchin;
        punchin = new PunchIn(newTab);

        QGridLayout *gridLayout_tab;
        gridLayout_tab = new QGridLayout(newTab);
        gridLayout_tab->setSpacing(6);
        gridLayout_tab->setContentsMargins(11, 11, 11, 11);
        gridLayout_tab->setObjectName(QString::fromUtf8("gridLayout_tab"));

        QSpacerItem *verticalSpacer;
        QSpacerItem *horizontalSpacer_2;
        QSpacerItem *horizontalSpacer;
        QSpacerItem *verticalSpacer_2;
        gridLayout_tab->addWidget(punchin, 2, 1, 1, 1);
        verticalSpacer = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer, 0, 1, 1, 1);
        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer_2, 2, 2, 1, 1);
        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer, 2, 0, 1, 1);
        verticalSpacer_2 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer_2, 3, 1, 1, 1);

        punchin->QueryTask(login_persid);

        ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ������ģʽ��¼"), QMessageBox::Ok);
    }
}

//��ʾǩ��ҳǩ
void MainWindow::on_punchout_action_triggered()
{
    if(login_mode != "����" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "ǩ��");

        PunchOut *punchout;
        punchout = new PunchOut(newTab);

        QGridLayout *gridLayout_tab;
        gridLayout_tab = new QGridLayout(newTab);
        gridLayout_tab->setSpacing(6);
        gridLayout_tab->setContentsMargins(11, 11, 11, 11);
        gridLayout_tab->setObjectName(QString::fromUtf8("gridLayout_tab"));

        QSpacerItem *verticalSpacer;
        QSpacerItem *horizontalSpacer_2;
        QSpacerItem *horizontalSpacer;
        QSpacerItem *verticalSpacer_2;
        gridLayout_tab->addWidget(punchout, 2, 1, 1, 1);
        verticalSpacer = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer, 0, 1, 1, 1);
        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer_2, 2, 2, 1, 1);
        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer, 2, 0, 1, 1);
        verticalSpacer_2 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer_2, 3, 1, 1, 1);

        punchout->QueryTask(login_persid);

        ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ������ģʽ��¼"), QMessageBox::Ok);
    }
}

//��ʾ������Ŀҳǩ
void MainWindow::on_addproject_action_triggered()
{
    if(login_mode == "����"){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "������Ŀ");

        AddProject *addproject;
        addproject = new AddProject(newTab);

        QGridLayout *gridLayout_tab;
        gridLayout_tab = new QGridLayout(newTab);
        gridLayout_tab->setSpacing(6);
        gridLayout_tab->setContentsMargins(11, 11, 11, 11);
        gridLayout_tab->setObjectName(QString::fromUtf8("gridLayout_tab"));

        QSpacerItem *verticalSpacer;
        QSpacerItem *horizontalSpacer_2;
        QSpacerItem *horizontalSpacer;
        QSpacerItem *verticalSpacer_2;
        gridLayout_tab->addWidget(addproject, 2, 1, 1, 1);
        verticalSpacer = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer, 0, 1, 1, 1);
        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer_2, 2, 2, 1, 1);
        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer, 2, 0, 1, 1);
        verticalSpacer_2 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer_2, 3, 1, 1, 1);

        ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ�ù���ģʽ��¼"), QMessageBox::Ok);
    }
}

//��ʾ��Ŀ�Ŷ�ҳǩ
void MainWindow::on_team_action_triggered()
{
    if(login_jobtyp == "��Ŀ����" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "�Ŷӷ���");

        Team *team;
        team = new Team(newTab);

        QGridLayout *gridLayout_tab;
        gridLayout_tab = new QGridLayout(newTab);
        gridLayout_tab->setSpacing(6);
        gridLayout_tab->setContentsMargins(11, 11, 11, 11);
        gridLayout_tab->setObjectName(QString::fromUtf8("gridLayout_tab"));

        QSpacerItem *verticalSpacer;
        QSpacerItem *horizontalSpacer_2;
        QSpacerItem *horizontalSpacer;
        QSpacerItem *verticalSpacer_2;
        gridLayout_tab->addWidget(team, 2, 1, 1, 1);
        verticalSpacer = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer, 0, 1, 1, 1);
        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer_2, 2, 2, 1, 1);
        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer, 2, 0, 1, 1);
        verticalSpacer_2 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer_2, 3, 1, 1, 1);

        ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��Ҫ��֤���Ϊ��Ŀ����"), QMessageBox::Ok);
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

    QGridLayout *gridLayout_tab;
    gridLayout_tab = new QGridLayout(newTab);
    gridLayout_tab->setSpacing(6);
    gridLayout_tab->setContentsMargins(11, 11, 11, 11);
    gridLayout_tab->setObjectName(QString::fromUtf8("gridLayout_tab"));

    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    gridLayout_tab->addWidget(projectgrade, 2, 1, 1, 1);
    verticalSpacer = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
    gridLayout_tab->addItem(verticalSpacer, 0, 1, 1, 1);
    horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
    gridLayout_tab->addItem(horizontalSpacer_2, 2, 2, 1, 1);
    horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
    gridLayout_tab->addItem(horizontalSpacer, 2, 0, 1, 1);
    verticalSpacer_2 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
    gridLayout_tab->addItem(verticalSpacer_2, 3, 1, 1, 1);

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

    QGridLayout *gridLayout_tab;
    gridLayout_tab = new QGridLayout(newTab);
    gridLayout_tab->setSpacing(6);
    gridLayout_tab->setContentsMargins(11, 11, 11, 11);
    gridLayout_tab->setObjectName(QString::fromUtf8("gridLayout_tab"));

    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    gridLayout_tab->addWidget(perslevel, 2, 1, 1, 1);
    verticalSpacer = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
    gridLayout_tab->addItem(verticalSpacer, 0, 1, 1, 1);
    horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
    gridLayout_tab->addItem(horizontalSpacer_2, 2, 2, 1, 1);
    horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
    gridLayout_tab->addItem(horizontalSpacer, 2, 0, 1, 1);
    verticalSpacer_2 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
    gridLayout_tab->addItem(verticalSpacer_2, 3, 1, 1, 1);

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

    QGridLayout *gridLayout_tab;
    gridLayout_tab = new QGridLayout(newTab);
    gridLayout_tab->setSpacing(6);
    gridLayout_tab->setContentsMargins(11, 11, 11, 11);
    gridLayout_tab->setObjectName(QString::fromUtf8("gridLayout_tab"));

    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    gridLayout_tab->addWidget(persgrade, 2, 1, 1, 1);
    verticalSpacer = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
    gridLayout_tab->addItem(verticalSpacer, 0, 1, 1, 1);
    horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
    gridLayout_tab->addItem(horizontalSpacer_2, 2, 2, 1, 1);
    horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
    gridLayout_tab->addItem(horizontalSpacer, 2, 0, 1, 1);
    verticalSpacer_2 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
    gridLayout_tab->addItem(verticalSpacer_2, 3, 1, 1, 1);

    ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ�ù���ģʽ��¼"), QMessageBox::Ok);
    }
}

//��ʾ�������ҳǩ
void MainWindow::on_task_action_triggered()
{
    if(login_jobtyp == "��Ŀ����" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "�������");

        Task *task;
        task = new Task(newTab);

        QGridLayout *gridLayout_tab;
        gridLayout_tab = new QGridLayout(newTab);
        gridLayout_tab->setSpacing(6);
        gridLayout_tab->setContentsMargins(11, 11, 11, 11);
        gridLayout_tab->setObjectName(QString::fromUtf8("gridLayout_tab"));

        QSpacerItem *verticalSpacer;
        QSpacerItem *horizontalSpacer_2;
        QSpacerItem *horizontalSpacer;
        QSpacerItem *verticalSpacer_2;
        gridLayout_tab->addWidget(task, 2, 1, 1, 1);
        verticalSpacer = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer, 0, 1, 1, 1);
        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer_2, 2, 2, 1, 1);
        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer, 2, 0, 1, 1);
        verticalSpacer_2 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer_2, 3, 1, 1, 1);

        ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��Ҫ��֤���Ϊ��Ŀ����"), QMessageBox::Ok);
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

        QGridLayout *gridLayout_tab;
        gridLayout_tab = new QGridLayout(newTab);
        gridLayout_tab->setSpacing(6);
        gridLayout_tab->setContentsMargins(11, 11, 11, 11);
        gridLayout_tab->setObjectName(QString::fromUtf8("gridLayout_tab"));

        QSpacerItem *verticalSpacer;
        QSpacerItem *horizontalSpacer_2;
        QSpacerItem *horizontalSpacer;
        QSpacerItem *verticalSpacer_2;
        gridLayout_tab->addWidget(salary, 2, 1, 1, 1);
        verticalSpacer = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer, 0, 1, 1, 1);
        horizontalSpacer_2 = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer_2, 2, 2, 1, 1);
        horizontalSpacer = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
        gridLayout_tab->addItem(horizontalSpacer, 2, 0, 1, 1);
        verticalSpacer_2 = new QSpacerItem(2, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);
        gridLayout_tab->addItem(verticalSpacer_2, 3, 1, 1, 1);

        ui->tabWidget->setCurrentWidget(newTab);
    }else{
        QMessageBox::information(this, tr("����"), tr("��ʹ�ù���ģʽ��¼"), QMessageBox::Ok);
    }
}
