#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->lineEdit_username->setFocus();
    ui->label_error->setHidden(true);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_login_clicked()
{
    if(ui->lineEdit_username->text().isEmpty())
    {
        QMessageBox::information(this, tr("错误"), tr("请输入用户名"), QMessageBox::Ok);
        ui->lineEdit_username->setFocus();
    }else if(ui->lineEdit_passwd->text().isEmpty()){
        QMessageBox::information(this, tr("错误"), tr("请输入密码"), QMessageBox::Ok);
        ui->lineEdit_passwd->setFocus();
    }else{
        QString username;
        QString passwd;
        username = ui->lineEdit_username->text();
        passwd = ui->lineEdit_passwd->text();
        QSqlQuery query;
        query.prepare("select password from login where loginid = ?");
        query.addBindValue(username);
        query.exec();
        query.next();
        if(query.value(0).toString() != passwd)
        {
            QMessageBox::information(this, tr("错误"), tr("用户名或密码错误，请重新输入"), QMessageBox::Ok);
        }else{
            this->close();
        }
    }
}

void Login::on_pushButton_quit_clicked()
{
    this->close();
}
