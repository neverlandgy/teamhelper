#ifndef SALARYDIALOG_H
#define SALARYDIALOG_H

#include <QDialog>

namespace Ui {
class SalaryDialog;
}

class SalaryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SalaryDialog(QWidget *parent = 0);
    ~SalaryDialog();

private slots:
    void on_buttonBox_accepted();

    void on_toolBox_currentChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SalaryDialog *ui;
};

#endif // SALARYDIALOG_H
