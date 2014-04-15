#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "about.h"
#include "myinfo.h"
#include "punchin.h"
#include "punchout.h"
#include "addproject.h"
#include "team.h"
#include "projectgrade.h"
#include "perslevel.h"
#include "persgrade.h"
#include "task.h"
#include "salary.h"
#include "extern.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_tabWidget_tabCloseRequested(int index);

    void on_about_action_triggered();

    void on_myinfo_action_triggered();

    void on_punchin_action_triggered();

    void on_punchout_action_triggered();

    void on_addproject_action_triggered();

    void on_team_action_triggered();

    void on_teamgrade_action_triggered();

    void on_perslevel_action_triggered();

    void on_persgrade_action_triggered();

    void on_task_action_triggered();

    void on_salary_action_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
