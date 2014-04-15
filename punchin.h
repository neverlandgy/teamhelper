#ifndef PUNCHIN_H
#define PUNCHIN_H

#include <QFrame>
#include <QTimer>
#include <QSqlQuery>
#include "extern.h"

namespace Ui {
class PunchIn;
}

class PunchIn : public QFrame
{
    Q_OBJECT

public:
    explicit PunchIn(QWidget *parent = 0);
    ~PunchIn();
    void QueryTask(int persid);


private slots:
    void UpdateTime();

    void on_pushButton_clicked();

private:
    Ui::PunchIn *ui;


};

#endif // PUNCHIN_H
