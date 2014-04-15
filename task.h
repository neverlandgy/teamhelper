#ifndef TASK_H
#define TASK_H

#include <QFrame>
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

private:
    Ui::Task *ui;
};

#endif // TASK_H
