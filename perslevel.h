#ifndef PERSLEVEL_H
#define PERSLEVEL_H

#include <QFrame>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
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

private slots:
    void on_pushButton_commit_clicked();

    void on_pushButton_revert_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_add_clicked();

private:
    Ui::PersLevel *ui;
    QSqlTableModel *model;
};

#endif // PERSLEVEL_H
