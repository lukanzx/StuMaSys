#include "ModifyStudentPassword.h"
#include "ui_ModifyStudentPassword.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>

ModifyStudentPassword::ModifyStudentPassword(QWidget *parent) :QWidget(parent),ui(new Ui::ModifyStudentPassword)
{
    ui->setupUi(this);
    initScreen();
}

ModifyStudentPassword::~ModifyStudentPassword()
{
    delete ui;
}

void ModifyStudentPassword::initScreen()
{
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setWindowTitle("修改学生密码");
    setFixedSize(500,333);
}

void ModifyStudentPassword::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,333,QPixmap(":/IMG_5863.JPG"));
}

void ModifyStudentPassword::ModifyStudentPasswordFunction(QString stuid, QString getPassword)
{

    bool m = StudentPasswordTable::getInstance()->SetStudentPassword(stuid,getPassword);
    if(m==true){
        QMessageBox::information(this,"提示","密码修改成功！");
    }
    else if(m == false){
        QMessageBox::information(this,"提示","密码修改失败！");
    }
}

void ModifyStudentPassword::on_pushButton_back_clicked()
{
    emit this->backToThePreviousWindow();
}

void ModifyStudentPassword::on_pushButton_submit_clicked()
{
    QString stuid=ui->lineEdit_stuid->text();
    QString getPassword=ui->lineEdit_newPass->text();
    QString againPass=ui->lineEdit_againPass->text();
    if(getPassword != againPass){
        QMessageBox::critical(this,"提示","两次密码输入不同！\n请重新输入。");
    }
    else{
        ModifyStudentPasswordFunction(stuid,getPassword);
    }
}


void ModifyStudentPassword::on_lineEdit_stuid_editingFinished()
{
    QString stuid=ui->lineEdit_stuid->text();
    bool m = StudentPasswordTable::getInstance()->checkStuIdExists(stuid);
    if(m==true){
        vector<QString> v;
        v = StudentsBasicInformation::getInstance()->GetStudentInformation(stuid);
        ui->lineEdit_sname->setText(v[0]); 
    }
    else{
        QMessageBox::information(this,"提示","无此学生\n请检查学号是否正确\n请重新输入");
        ui->lineEdit_stuid->setText("");
        ui->lineEdit_sname->setText("");
    }
}









