#include "AllStudentGrades.h"
#include "ui_AllStudentGrades.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>


AllStudentGrades::AllStudentGrades(QWidget *parent) :QWidget(parent),ui(new Ui::AllStudentGrades)
{
    ui->setupUi(this);
    model=new QSqlQueryModel;
    addstudentgrades=new AddStudentGrades;
    initScreen();
    studentGradesView();
    connect(addstudentgrades,&AddStudentGrades::backToThePreviousWindow,[=](){
        addstudentgrades->hide();
        this->show();
    });
}


AllStudentGrades::~AllStudentGrades()
{
    delete ui;
}


void AllStudentGrades::initScreen()
{
    setWindowTitle("学生成绩展示");
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setFixedSize(500,333);
    ui->tableView->setStyleSheet("border :1px ;background-color: rgba(0,0,0,0)");
}


void AllStudentGrades::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,333,QPixmap(":/IMG_5859.JPG"));
}


void AllStudentGrades::studentGradesView()
{
    model = StudentGradesTable::getInstance()->ShowGradesInformationQueryModel();

    proxyModel=new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);

    proxyModel->setHeaderData(0,Qt::Horizontal,tr("学号"));
    proxyModel->setHeaderData(1,Qt::Horizontal,tr("姓名"));
    proxyModel->setHeaderData(2,Qt::Horizontal,tr("数学"));
    proxyModel->setHeaderData(3,Qt::Horizontal,tr("英语"));
    proxyModel->setHeaderData(4,Qt::Horizontal,tr("C++"));
    proxyModel->setHeaderData(5,Qt::Horizontal,tr("总分"));

    ui->tableView->setModel(proxyModel);
    ui->tableView->show();
    ui->tableView->setColumnWidth(0,80);
    ui->tableView->setColumnWidth(1,60);
    ui->tableView->setColumnWidth(2,50);
    ui->tableView->setColumnWidth(3,50);
    ui->tableView->setColumnWidth(4,50);
    ui->tableView->setColumnWidth(5,50);

}


void AllStudentGrades::on_pushButton_back_clicked()
{
    emit this->backToThePreviousWindow();
}


void AllStudentGrades::on_comboBox_activated(int index)
{
    num=index;
}


void AllStudentGrades::on_pushButton_asc_clicked()
{
    proxyModel->sort(num,Qt::AscendingOrder);
    qDebug()<<num;
}


void AllStudentGrades::on_pushButton_desc_clicked()
{
    proxyModel->sort(num,Qt::DescendingOrder);
    qDebug()<<num;

}


void AllStudentGrades::on_pushButton_add_clicked()
{
    this->hide();
    addstudentgrades->show();
}


void AllStudentGrades::on_pushButton_refresh_clicked()
{
    studentGradesView();
}
