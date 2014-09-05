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
    if(login_mode != "管理" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "个人信息");
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
        QMessageBox::information(this, tr("错误"), tr("请使用正常模式登录"), QMessageBox::Ok);
    }
}

//显示签到页签
void MainWindow::on_punchin_action_triggered()
{
    if(login_mode != "管理" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "签到");

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
        QMessageBox::information(this, tr("错误"), tr("请使用正常模式登录"), QMessageBox::Ok);
    }
}

//显示签退页签
void MainWindow::on_punchout_action_triggered()
{
    if(login_mode != "管理" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "签退");

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
        QMessageBox::information(this, tr("错误"), tr("请使用正常模式登录"), QMessageBox::Ok);
    }
}

//显示新增项目页签
void MainWindow::on_addproject_action_triggered()
{
    if(login_mode == "管理"){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "新增项目");

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
        QMessageBox::information(this, tr("错误"), tr("请使用管理模式登录"), QMessageBox::Ok);
    }
}

//显示项目团队页签
void MainWindow::on_team_action_triggered()
{
    if(login_jobtyp == "项目经理" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "团队分配");

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
        QMessageBox::information(this, tr("错误"), tr("需要验证身份为项目经理"), QMessageBox::Ok);
    }
}


//显示项目打分页签
void MainWindow::on_teamgrade_action_triggered()
{
    if(login_mode == "管理" ){
    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab, "项目打分");

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
        QMessageBox::information(this, tr("错误"), tr("请使用管理模式登录"), QMessageBox::Ok);
    }
}

//显示员工评级页签
void MainWindow::on_perslevel_action_triggered()
{
    if(login_mode == "管理" ){
    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab, "员工管理");

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
        QMessageBox::information(this, tr("错误"), tr("请使用管理模式登录"), QMessageBox::Ok);
    }
}

//显示员工打分页签
void MainWindow::on_persgrade_action_triggered()
{
    if(login_mode == "管理" ){
    QWidget *newTab = new QWidget(ui->tabWidget);
    ui->tabWidget->addTab(newTab, "员工打分");

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
        QMessageBox::information(this, tr("错误"), tr("请使用管理模式登录"), QMessageBox::Ok);
    }
}

//显示任务分配页签
void MainWindow::on_task_action_triggered()
{
    if(login_jobtyp == "项目经理" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "任务分配");

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
        QMessageBox::information(this, tr("错误"), tr("需要验证身份为项目经理"), QMessageBox::Ok);
    }
}

//显示工资发放页签
void MainWindow::on_salary_action_triggered()
{
    if(login_mode == "管理" ){
        QWidget *newTab = new QWidget(ui->tabWidget);
        ui->tabWidget->addTab(newTab, "工资发放");

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
        QMessageBox::information(this, tr("错误"), tr("请使用管理模式登录"), QMessageBox::Ok);
    }
}
