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

private:
    Ui::Salary *ui;
};

#endif // SALARY_H
