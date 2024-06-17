#include "StudentFeedback.h"
#include "ui_StudentFeedback.h"


#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>




StudentFeedback::StudentFeedback(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentFeedback)
{
    ui->setupUi(this);
    iniScreen();
}
StudentFeedback::~StudentFeedback()
{
    delete ui;
}
void StudentFeedback::iniScreen()
{
    setWindowTitle("反馈建议");
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setFixedSize(500,333);
}
void StudentFeedback::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,333,QPixmap(":/IMG_5866.JPG"));
}

void StudentFeedback::modifyPassword(QString getOldPass, QString newPass)
{






















}




void StudentFeedback::on_pushButton_clicked()
{
     emit this->backToThePreviousWindow();
}

void StudentFeedback::on_pushButton_2_clicked()
{
        QString text=removeSpace(ui->pushButton_2->text());
        QMessageBox::information(this,"提示","提交反馈成功!");
}
