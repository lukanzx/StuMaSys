#include "StudentEpidemicManagement.h"
#include "ui_StudentEpidemicManagement.h"
#include "addstudent.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>


StudentEpidemicManagement::StudentEpidemicManagement(QWidget *parent) :QWidget(parent),ui(new Ui::StudentEpidemicManagement)
{
    ui->setupUi(this);
    initScreen();
}


StudentEpidemicManagement::~StudentEpidemicManagement()
{
    delete ui;
}


void StudentEpidemicManagement::on_pushButton_back_clicked()
{
    emit this->backToThePreviousWindow();
}


void  StudentEpidemicManagement::initScreen()
{
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setFixedSize(500,333);
    setWindowTitle("学生健康信息");
}

void StudentEpidemicManagement::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,333,QPixmap(":/IMG_5860.JPG"));
}


bool StudentEpidemicManagement::checkStuId(QString stid)
{
    QString stuid=ui->lineEdit_stid->text();
    bool m = StudentPasswordTable::getInstance()->checkStuIdExists(stuid);
    if(m==true){
        vector<QString> v;
        v = StudentsBasicInformation::getInstance()->GetStudentInformation(stuid);
        ui->lineEdit_name->setText(v[0]); 
    }
    else{
        QMessageBox::information(this,"提示","无此学生\n请检查学号是否正确\n请重新输入");
        ui->lineEdit_stid->setText("");
        ui->lineEdit_name->setText("");
    }
}

void StudentEpidemicManagement::SetHealthCodeState()
{










}

void StudentEpidemicManagement::on_pushButton_submit22_clicked()
{
   BodyTemperature=removeSpace(ui->lineEdit_BodyTemperature->text());
   HealthCode=removeSpace(ui->comboBox_HealthCode->currentText());
   SetHealthCodeState();
}
















