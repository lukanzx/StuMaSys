#include "StudentHealth.h"
#include "ui_StudentHealth.h"
#include "AddStudent.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>


StudentHealth::StudentHealth(QWidget *parent) :QWidget(parent),ui(new Ui::StudentHealth)
{
    ui->setupUi(this);
    initScreen();
    QString sid = StudentPasswordTable::getInstance()->GetUserId();
    this->stid = sid;
    ui->lineEdit_id->setText(stid);
    ui->lineEdit_id->setReadOnly(true);
}


StudentHealth::~StudentHealth()
{
    delete ui;
}


void StudentHealth::on_pushButton_back_clicked()
{
    emit this->backToThePreviousWindow();
}


void  StudentHealth::initScreen()
{
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setFixedSize(500,333);
    setWindowTitle("学生健康信息");
}


void StudentHealth::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,333,QPixmap(":/IMG_5860.JPG"));
}


bool StudentHealth::checkStuId(QString stid)
{

    return StudentPasswordTable::getInstance()->checkStuIdExists(stid);
}


void StudentHealth::setHealthCPdeState()
{












}


void StudentHealth::on_pushButton_add_clicked()
{
   BodyTemperature=removeSpace(ui->lineEdit_BodyTemperature->text());
   HealthCode=removeSpace(ui->comboBox_HealthCode->currentText());
   setHealthCPdeState();
}














