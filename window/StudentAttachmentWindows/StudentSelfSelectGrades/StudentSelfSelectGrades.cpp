#include "StudentSelfSelectGrades.h"
#include "ui_StudentSelfSelectGrades.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>


StudentSelfSelectGrades::StudentSelfSelectGrades(QWidget *parent) :QWidget(parent),ui(new Ui::StudentSelfSelectGrades)
{
    ui->setupUi(this);
    initScreen();
    QString sid = StudentPasswordTable::getInstance()->GetUserId();
    this->sid = sid;
    getDateAndShow();
}


StudentSelfSelectGrades::~StudentSelfSelectGrades()
{
    delete ui;
}


void StudentSelfSelectGrades::initScreen()
{
    setWindowTitle("个人成绩展示");
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setFixedSize(500,333);
}


void StudentSelfSelectGrades::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,333,QPixmap(":/IMG_5864.JPG"));
}


void StudentSelfSelectGrades::getDateAndShow()
{
    vector<QString> v = StudentGradesTable::getInstance()->GetStudentGrades(sid);
    math=v[0];
    english=v[1];
    cplusplus=v[2];
    avgGrade=v[3];
    ui->lineEdit->setText(math);
    ui->lineEdit_2->setText(english);
    ui->lineEdit_3->setText(cplusplus);
    ui->lineEdit_4->setText(avgGrade);

}


QString StudentSelfSelectGrades::convert(float f)
{
        QString str;
        str=QString("%1").arg(f,0,'f',3);
        return str;
}



void StudentSelfSelectGrades::on_pushButton_back_clicked()
{
    emit this->backToThePreviousWindow();
}
