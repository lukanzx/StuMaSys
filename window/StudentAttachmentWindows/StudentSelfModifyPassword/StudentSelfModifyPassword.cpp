#include "StudentSelfModifyPassword.h"
#include "ui_StudentSelfModifyPassword.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>


StudentSelfModifyPassword::StudentSelfModifyPassword(QWidget *parent) :QWidget(parent),ui(new Ui::StudentSelfModifyPassword)
{
    ui->setupUi(this);
    iniScreen();
}


StudentSelfModifyPassword::~StudentSelfModifyPassword()
{
    delete ui;
}


void StudentSelfModifyPassword::iniScreen()
{
    setWindowTitle("修改密码");
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setFixedSize(500,333);
}


void StudentSelfModifyPassword::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,333,QPixmap(":/IMG_5866.JPG"));
}


void StudentSelfModifyPassword::modifyPassword(QString getOldPass, QString newPass)
{
    if(sid.size()==0){
        QString sid = StudentPasswordTable::getInstance()->GetUserId();
        this->sid = sid;
    }
    bool m = StudentPasswordTable::getInstance()->SetStudentPasswordNeddIdAndOldPass(sid,getOldPass,newPass);
    if(m==true){
        QMessageBox::information(this,"提示","修改密码成功!");
    }
    else{
        QMessageBox::critical(this,"警告","初始密码输入错误！\n请重新输入！\n若忘记密码，请联系学校管理员修改");
    }
}


void StudentSelfModifyPassword::on_pushButton_back_clicked()
{
    emit this->backToThePreviousWindow();
}


void StudentSelfModifyPassword::on_pushButton_modifyPass_clicked()
{
    QString oldPass=removeSpace(ui->lineEdit_oldPass->text());
    QString newPass=removeSpace(ui->lineEdit_newPass->text());
    QString againPass=removeSpace(ui->lineEdit_againPass->text());

    if(newPass != againPass){
        QMessageBox::information(this,"注意","两次密码输入不同，请重新输入！");
    }
    else{
        if(newPass != ""){
            modifyPassword(oldPass,newPass);
        }
        else{
            QMessageBox::information(this,"提示","新密码不能为空\n请重新输入");
        }
    }
}


void StudentSelfModifyPassword::on_lineEdit_newPass_editingFinished()
{
    if(!isProperPassword(removeSpace(ui->lineEdit_newPass->text()))){
        QMessageBox::information(this,"提示","新密码位数必须大于6位且小于20位\n请重新输入");
        ui->lineEdit_newPass->setText("");
    }
}
