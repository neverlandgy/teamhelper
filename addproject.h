#ifndef ADDPROJECT_H
#define ADDPROJECT_H

#include <QFrame>
#include <QSqlQuery>

namespace Ui {
class AddProject;
}

class AddProject : public QFrame
{
    Q_OBJECT

public:
    explicit AddProject(QWidget *parent = 0);
    ~AddProject();

private slots:
    void on_commit_clicked();

private:
    Ui::AddProject *ui;
};

#endif // ADDPROJECT_H
