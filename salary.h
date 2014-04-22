#ifndef SALARY_H
#define SALARY_H

#include <QFrame>
#include "extern.h"

namespace Ui {
class Salary;
}

class Salary : public QFrame
{
    Q_OBJECT

public:
    explicit Salary(QWidget *parent = 0);
    ~Salary();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_salary_clicked();

private:
    Ui::Salary *ui;
};

#endif // SALARY_H
