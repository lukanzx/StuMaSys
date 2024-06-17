#include "AllStudentInformation.h"
#include "ui_AllStudentInformation.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>


AllStudentInformation::AllStudentInformation(QWidget *parent) :QWidget(parent),ui(new Ui::AllStudentInformation)
{
    ui->setupUi(this);
    initScreen();
    studentInfoView();
}


AllStudentInformation::~AllStudentInformation()
{
    delete ui;
}


void AllStudentInformation::initScreen()
{
    setFixedSize(839,527);
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setWindowTitle("学生信息展示");
    ui->tableView->setStyleSheet("border :1px ;background-color: rgba(0,0,0,0)");
    ui->widget_btn->setStyleSheet("border:0px;background-color: rgba(0,0,0,50);");
    ui->pushButton_refresh->setStyleSheet("height:40px;background-color:rgba(227,168,105,1)");
    ui->pushButton_add->setStyleSheet("height:40px;background-color:rgba(227,168,105,1)");
    ui->pushButton_asc->setStyleSheet("height:40px;background-color:rgba(227,168,105,1)");
    ui->pushButton_back->setStyleSheet("height:40px;background-color:rgba(227,168,105,1)");
    ui->pushButton_cancel->setStyleSheet("height:40px;background-color:rgba(227,168,105,1)");
    ui->pushButton_delete->setStyleSheet("height:40px;background-color:rgba(227,168,105,1)");
    ui->pushButton_desc->setStyleSheet("height:40px;background-color:rgba(227,168,105,1)");
}


void AllStudentInformation::studentInfoView()
{
    model = StudentsBasicInformation::getInstance()->ShowInformationTableModel(this);
    model->setTable("StudentsBasicInformation");
    model->setHeaderData(0,Qt::Horizontal,QVariant("学号"));
    model->setHeaderData(1,Qt::Horizontal,QVariant("姓名"));
    model->setHeaderData(2,Qt::Horizontal,QVariant("性别"));
    model->setHeaderData(3,Qt::Horizontal,QVariant("年龄"));
    model->setHeaderData(4,Qt::Horizontal,QVariant("籍贯"));
    model->setHeaderData(5,Qt::Horizontal,QVariant("专业"));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}


void AllStudentInformation::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,839,527,QPixmap(":/IMG_5859.JPG"));
}


void AllStudentInformation::on_pushButton_refresh_clicked()
{
    model->submitAll();
    model->select();
}


void AllStudentInformation::on_pushButton_cancel_clicked()
{
    model->revertAll();
}


void AllStudentInformation::on_pushButton_add_clicked()
{
    model->insertRow(model->rowCount());
}


void AllStudentInformation::on_pushButton_delete_clicked()
{
    int selectRow=ui->tableView->currentIndex().row();
    if(selectRow >= 0)
    {
        int del=QMessageBox::question(this,"提示","是否要删除此学生信息\n删除后数据无法恢复，请慎重考虑!",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
        if(del==QMessageBox::Yes)
        {
            model->removeRow(selectRow);
            model->submitAll();
        }
        else return;
    }
}


void AllStudentInformation::on_pushButton_asc_clicked()
{
    model->sort(0,Qt::AscendingOrder);
}


void AllStudentInformation::on_pushButton_desc_clicked()
{
    model->sort(0,Qt::DescendingOrder);
}


void AllStudentInformation::on_pushButton_back_clicked()
{
    emit this->backToThePreviousWindow();
}
