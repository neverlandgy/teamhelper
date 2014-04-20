#ifndef TASK_H
#define TASK_H

#include <QFrame>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "extern.h"


namespace Ui {
class Task;
}

class Task : public QFrame
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = 0);
    ~Task();

private slots:
    void on_pushButton_clicked();

    void on_dateEdit_start_dateChanged();

private:
    Ui::Task *ui;
};

#endif // TASK_H
