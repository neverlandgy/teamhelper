#ifndef PERSLEVEL_H
#define PERSLEVEL_H

#include <QFrame>
#include "extern.h"

namespace Ui {
class PersLevel;
}

class PersLevel : public QFrame
{
    Q_OBJECT

public:
    explicit PersLevel(QWidget *parent = 0);
    ~PersLevel();

private:
    Ui::PersLevel *ui;
};

#endif // PERSLEVEL_H
