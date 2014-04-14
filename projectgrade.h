#ifndef PROJECTGRADE_H
#define PROJECTGRADE_H

#include <QFrame>

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

private:
    Ui::ProjectGrade *ui;
};

#endif // PROJECTGRADE_H
