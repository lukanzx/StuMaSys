#include "StudentMail.h"
#include "ui_StudentMail.h"

StudentMail::StudentMail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentMail)
{
    ui->setupUi(this);
}

StudentMail::~StudentMail()
{
    delete ui;
}
