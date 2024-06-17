#include "AddStudentGrades.h"
#include "ui_AddStudentGrades.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>


AddStudentGrades::AddStudentGrades(QWidget *parent) :QWidget(parent),ui(new Ui::AddStudentGrades)
{
    ui->setupUi(this);
    initScreen();
}


AddStudentGrades::~AddStudentGrades()
{
    delete ui;
}


void AddStudentGrades::initScreen()
{
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setFixedSize(500,333);
    setWindowTitle("添加学生成绩");
}


void AddStudentGrades::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,333,QPixmap(":/IMG_5858.JPG"));
}


bool AddStudentGrades::checkStuId(QString stid)
{
  return StudentPasswordTable::getInstance()->checkStuIdExists(stid);
}


void AddStudentGrades::setGrades()
{
    bool m = StudentGradesTable::getInstance()->AddOneStudentGradesAndSetGradesAndNotNull(stid,math,english,cpp);
    if(m){
        QMessageBox::information(this,"提示","添加成绩成功");
    }
    else{
        QMessageBox::information(this,"提示","添加成绩失败");
    }

}


void AddStudentGrades::on_pushButton_back_clicked()
{
    emit this->backToThePreviousWindow();
}


void AddStudentGrades::on_lineEdit_stid_editingFinished()
{
    stid=removeSpace(ui->lineEdit_stid->text());
    if(!checkStuId(stid) || !isProperId(stid)){
        QMessageBox::critical(this,"警告","此账号输入错误！");
        qDebug()<<"账号有问题";
        ui->lineEdit_stid->setText("");
    }
}


void AddStudentGrades::on_pushButton_submit_clicked()
{
    english=removeSpace(ui->lineEdit_english->text());
    math=removeSpace(ui->lineEdit_math->text());
    cpp=removeSpace(ui->lineEdit_c->text());
    setGrades();
}
