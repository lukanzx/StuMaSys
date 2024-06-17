#include "Student.h"
#include "ui_Student.h"

Student::Student(QWidget *parent) :QMainWindow(parent),ui(new Ui::Student)
{
    ui->setupUi(this);

    initScreen();

    studentselfshowinformation = new StudentSelfShowInformation();
    studentselfmodifypassword = new StudentSelfModifyPassword();
    studenthealth = new StudentHealth();
    studentnotes = new StudentNotes();
    studentselfselectgrades = new StudentSelfSelectGrades();
    studentmail = new StudentMail();
    studentfeedback = new StudentFeedback();

    
    SatelliteWindoweBackTheUpperLevelSignalAndSlotBind();
}


Student::~Student()
{
    delete ui;
}


void Student::initScreen()
{

}


void Student::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0,0,500,333,QPixmap(":/IMG_5867.JPG"));
};


void Student::SatelliteWindoweBackTheUpperLevelSignalAndSlotBind()
{
    
    connect(studentselfshowinformation,&StudentSelfShowInformation::backToThePreviousWindow,[=](){
                    studentselfshowinformation->hide();
                    this->show();
                }
           );

    
    connect(studentselfmodifypassword,&StudentSelfModifyPassword::backToThePreviousWindow,[=](){
                    studentselfmodifypassword->hide();
                    this->show();
                }
           );

    
    connect(studenthealth,&StudentHealth::backToThePreviousWindow,[=](){
                    studenthealth->hide();
                    this->show();
                }
           );

    
    connect(studentnotes,&StudentNotes::backToThePreviousWindow,[=](){
                    studentnotes->hide();
                    this->show();
                }
           );

    
    connect(studentselfselectgrades,&StudentSelfSelectGrades::backToThePreviousWindow,[=](){
                    studentselfselectgrades->hide();
                    this->show();
                }
           );

    
    connect(studentmail,&StudentMail::backToThePreviousWindow,[=](){
                    studentmail->hide();
                    this->show();
                }
           );

    
    connect(studentfeedback,&StudentFeedback::backToThePreviousWindow,[=](){
                    studentfeedback->hide();
                    this->show();
                }
           );

}


void Student::on_pushButton_StudentSelfShowInformation_clicked()
{
    this->hide();
    studentselfshowinformation->show();
}

void Student::on_pushButton_StudentSelfModifyPassword_clicked()
{
    this->hide();
    studentselfmodifypassword->show();
}


void Student::on_pushButton_StudentHealth_clicked()
{
    this->hide();
    studenthealth->show();
}


void Student::on_pushButton_StudentNotes_clicked()
{
    this->hide();
    studentnotes->show();
}


void Student::on_pushButton_StudentSelfSelectGrades_clicked()
{
    this->hide();
    studentselfselectgrades->show();
}


void Student::on_pushButton_StudentMail_clicked()
{
    this->hide();
    studentmail->show();
}


void Student::on_pushButton_StudentFeedback_clicked()
{
    this->hide();
    studentfeedback->show();
}

void Student::on_pushButton_backToThePreviousWindow_clicked()
{
    emit this->backToThePreviousWindow();
}

