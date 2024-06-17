#include "ModifyAdministratorPassword.h"
#include "ui_ModifyAdministratorPassword.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>


ModifyAdministratorPassword::ModifyAdministratorPassword(QWidget *parent) :QWidget(parent),ui(new Ui::ModifyAdministratorPassword)
{
    ui->setupUi(this);
    initScreen();
}


ModifyAdministratorPassword::~ModifyAdministratorPassword()
{
    delete ui;
}


void ModifyAdministratorPassword::initScreen()
{
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setWindowTitle("修改管理员密码");
    setFixedSize(500,333);
}


void ModifyAdministratorPassword::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,333,QPixmap(":/IMG_5861.JPG"));
}


void ModifyAdministratorPassword::modifyPassword(QString getOldPass, QString newPass)
{


    bool m = AdministratorPasswordTable::getInstance()->ModifyAdministratorPassword(getOldPass,newPass);
    if(m==true){
         QMessageBox::information(this,"提示","密码修改成功！");
    }else{
        QMessageBox::critical(this,"警告","初始密码输入错误！\n请重新输入！");
    }
}


void ModifyAdministratorPassword::on_pushButton_back_clicked()
{
    emit this->backToThePreviousWindow();
}

void ModifyAdministratorPassword::on_pushButton_submit_clicked()
{
    QString oldPass=removeSpace(ui->lineEdit_oldPass->text());
    QString newPass=removeSpace(ui->lineEdit_newPass->text());
    QString againPass=removeSpace(ui->lineEdit_againPass->text());
    if(newPass != againPass){
        QMessageBox::information(this,"注意","两次密码输入不同，请重新输入！");
    }
    else{
        modifyPassword(oldPass,newPass);
    }
}
