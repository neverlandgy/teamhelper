#ifndef MYINFO_H
#define MYINFO_H

#include <QFrame>

namespace Ui {
class MyInfo;
}

class MyInfo : public QFrame
{
    Q_OBJECT

public:
    explicit MyInfo(QWidget *parent = 0);
    ~MyInfo();
    void QureyPers();

private:
    Ui::MyInfo *ui;

};

#endif // MYINFO_H
