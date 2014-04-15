#include "login.h"
#include "ui_login.h"

QString login_mode;
int login_persid;

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->lineEdit_username->setFocus();
}

Login::~Login()
{
    delete ui;
}

//登录验证
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
        login_mode = ui->comboBox->currentText();
//TODO 全局变量
        QSqlQuery query;
        query.prepare("select password, persid from login where loginid = ? and mode = ?");
        query.addBindValue(username);
        query.addBindValue(login_mode);
        query.exec();
        query.next();

        login_persid = query.value(1).toInt();
        if(query.value(0).toString() != passwd)
        {
            QMessageBox::information(this, tr("错误"), tr("用户名或密码错误，请重新输入"), QMessageBox::Ok);
        }else{
            this->close();
        }
    }
}

//退出
void Login::on_pushButton_quit_clicked()
{
    this->close();

}
