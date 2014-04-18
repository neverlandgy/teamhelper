#ifndef PROJECTGRADE_H
#define PROJECTGRADE_H

#include <QFrame>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "extern.h"

namespace Ui {
class ProjectGrade;
}

class ProjectGrade : public QFrame
{
    Q_OBJECT

public:
    explicit ProjectGrade(QWidget *parent = 0);
    ~ProjectGrade();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_Diff_valueChanged();

    void on_horizontalSlider_Benefit_valueChanged();

    void on_horizontalSlider_Time_valueChanged();

    void on_horizontalSlider_Report_valueChanged();

    void on_horizontalSlider_Review_valueChanged();

private:
    Ui::ProjectGrade *ui;
    void setLcdNumber();
    QString projectname;
    int diff, benefit, time, report, review, grade;
};

#endif // PROJECTGRADE_H
