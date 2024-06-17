#include "RetrievePassword.h"
#include "ui_RetrievePassword.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>
#include <QPainter>

RetrievePassword::RetrievePassword(QWidget *parent) :QMainWindow(parent),ui(new Ui::RetrievePassword)
{
    ui->setupUi(this);
    iniScene();
}

RetrievePassword::~RetrievePassword()
{
    delete ui;
}

void RetrievePassword::iniScene()
{
    setFixedSize(500,312);
    setWindowTitle("找回密码");
    setWindowIcon(QIcon(":/imag/icon.jpg"));
}

void RetrievePassword::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,312,QPixmap(":/IMG_5859.JPG"));
}

void RetrievePassword::on_pushButton_back_clicked()
{
    emit this->backToThePreviousWindow();
}

void RetrievePassword::on_pushButton_submit_clicked()
{

    QMessageBox::critical(this,"提示","该功能暂时未开放\n请联系管理员找回密码!");
}













