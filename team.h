#ifndef TEAM_H
#define TEAM_H

#include <QFrame>
#include "draglistswidget.h"
#include <QSqlQuery>
#include "extern.h"



namespace Ui {
class Team;
}

class Team : public QFrame
{
    Q_OBJECT

public:
    explicit Team(QWidget *parent = 0);
    ~Team();

public slots:
    void on_leftButton_clicked();
    void on_rightButton_clicked();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Team *ui;
    void moveCurrentItem(DragListsWidget *source, DragListsWidget *target);

};

#endif // TEAM_H
