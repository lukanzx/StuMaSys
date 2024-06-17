#include "StudentSelfShowInformation.h"
#include "ui_StudentSelfShowInformation.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>


StudentSelfShowInformation::StudentSelfShowInformation(QWidget *parent) :QWidget(parent),ui(new Ui::StudentSelfShowInformation)
{
    ui->setupUi(this);
    iniScreen();
    getInformation();
    qDebug()<<"学生账号为："<<sid;
    ui->lineEdit_age->setText(sage);
    ui->lineEdit_id->setText(sid);
    ui->lineEdit_major->setText(smajor);
    ui->lineEdit_place->setText(splace);
    ui->lineEdit_sex->setText(ssex);
    ui->lineEdit_name->setText(sname);
    qDebug()<<"--------------------------";
    qDebug()<<sname;
    qDebug()<<ssex;
}


StudentSelfShowInformation::~StudentSelfShowInformation()
{
    delete ui;
}


void StudentSelfShowInformation::iniScreen()
{
    setWindowTitle("个人信息展示");
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setFixedSize(552,461);
}


void StudentSelfShowInformation::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,552,461,QPixmap(":/IMG_5865.JPG"));
}


void StudentSelfShowInformation::getInformation()
{
    if(sid.size()==0){
        QString sid = StudentPasswordTable::getInstance()->GetUserId();
        this->sid = sid;
    }
    vector<QString> v = StudentsBasicInformation::getInstance()->GetStudentInformation(sid);
    sname = v[0];
    ssex = v[1];
    sage = v[2];
    splace = v[3];
    smajor = v[4];
    qDebug()<<"v.size:    -->  "<<v.size();
    qDebug()<<"v[0]:    -->  "<<v[0];
    qDebug()<<"v[1]:    -->  "<<v[1];
    qDebug()<<"v[2]:    -->  "<<v[2];
    qDebug()<<"v[3]:    -->  "<<v[3];
    qDebug()<<"v[4]:    -->  "<<v[4];
}


void StudentSelfShowInformation::on_pushButton_back_clicked()
{
    emit this->backToThePreviousWindow();
}
