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

private slots:

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged();

private:
    Ui::PersGrade *ui;
    int persid, level, nofinishtask, task, taskgrade, nopunchdate, projectgrade, leaderappraise, persgrade;
    QString jobtyp;
};

#endif // PERSGRADE_H

