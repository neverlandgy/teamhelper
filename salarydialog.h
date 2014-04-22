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

private:
    Ui::SalaryDialog *ui;
};

#endif // SALARYDIALOG_H
