#ifndef PUNCHOUT_H
#define PUNCHOUT_H

#include <QFrame>
#include <QTimer>
#include <QSqlQuery>

namespace Ui {
class PunchOut;
}

class PunchOut : public QFrame
{
    Q_OBJECT

public:
    explicit PunchOut(QWidget *parent = 0);
    ~PunchOut();
    void QueryTask(int persid);

private slots:
    void UpdateTime();
    void on_pushButton_clicked();

private:
    Ui::PunchOut *ui;
};

#endif // PUNCHOUT_H
