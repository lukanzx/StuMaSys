#include "Register.h"
#include "ui_Register.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>
#include <QPainter>

Register::Register(QWidget *parent) :QMainWindow(parent),ui(new Ui::Register)
{
    ui->setupUi(this);
    iniScene();
}

Register::~Register()
{
    delete ui;
}

void Register::iniScene()
{
    setFixedSize(500,312);
    setWindowTitle("注册账号");
    setWindowIcon(QIcon(":/imag/icon.jpg"));
}

void Register::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,312,QPixmap(":/IMG_5868.JPG"));
}
void Register::on_pushButton_clicked()
{
     emit this->backToThePreviousWindow();
}

void Register::getInformation()
{

       xeuhao=removeSpace(ui->lineEdit_11->text());
       xingming=removeSpace(ui->lineEdit_22->text());
       mima=removeSpace(ui->lineEdit_33->text());
}

bool Register::setInformation()
{
































    return true;
}

void Register::on_pushButton_2_clicked()
{
    getInformation();
    
    if(isProperId(xeuhao))
    {
        qDebug()<<"账号正确";
        if(xeuhao !="" && isProperPassword(mima) && mima != "")
            setInformation();
        else QMessageBox::critical(this,"警告","添加失败！\n账号，密码，姓名三项不能为空!");
    }
    else QMessageBox::critical(this,"警告","学号格式错误");
}





