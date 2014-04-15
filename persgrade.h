#ifndef PERSGRADE_H
#define PERSGRADE_H

#include <QFrame>
#include "extern.h"

namespace Ui {
class PersGrade;
}

class PersGrade : public QFrame
{
    Q_OBJECT

public:
    explicit PersGrade(QWidget *parent = 0);
    ~PersGrade();

private:
    Ui::PersGrade *ui;
};

#endif // PERSGRADE_H
