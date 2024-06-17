#include "Administrator.h"
#include "ui_Administrator.h"

Administrator::Administrator(QWidget *parent) :QMainWindow(parent),ui(new Ui::Administrator)
{
    ui->setupUi(this);
    
    iniScene();
    
    
    allstudentinformation = new AllStudentInformation();            
    addstudent = new AddStudent();                                  
    allstudentgrades = new AllStudentGrades();                      
    modifyadministratorpassword = new ModifyAdministratorPassword();
    modifystudentinformation = new ModifyStudentInformation();      
    modifystudentpassword = new ModifyStudentPassword();            
    studentepidemicmanagement = new StudentEpidemicManagement();    
    

    SatelliteWindoweBackTheUpperLevelSignalAndSlotBind();
}


Administrator::~Administrator()
{
    delete ui;
}


void Administrator::iniScene()
{
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setWindowTitle("管理员操作界面");
    setFixedSize(500,333);
}


void Administrator::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,333,QPixmap(":/IMG_5863.JPG"));
}


void Administrator::SatelliteWindoweBackTheUpperLevelSignalAndSlotBind()
{
    
    connect(allstudentinformation,&AllStudentInformation::backToThePreviousWindow,[=](){
                    allstudentinformation->hide();
                    this->show();
                }
           );

    
    connect(addstudent,&AddStudent::backToThePreviousWindow,[=](){
                    addstudent->hide();
                    this->show();
                }
           );

    
    connect(allstudentgrades,&AllStudentGrades::backToThePreviousWindow,[=](){
                    allstudentgrades->hide();
                    this->show();
                }
           );

    
    connect(modifyadministratorpassword,&ModifyAdministratorPassword::backToThePreviousWindow,[=](){
                    modifyadministratorpassword->hide();
                    this->show();
                }
           );

    
    connect(modifystudentinformation,&ModifyStudentInformation::backToThePreviousWindow,[=](){
                    modifystudentinformation->hide();
                    this->show();
                }
           );

    
    connect(modifystudentpassword,&ModifyStudentPassword::backToThePreviousWindow,[=](){
                    modifystudentpassword->hide();
                    this->show();
                }
           );

    
    connect(studentepidemicmanagement,&StudentEpidemicManagement::backToThePreviousWindow,[=](){
                    studentepidemicmanagement->hide();
                    this->show();
                }
           );

}


void Administrator::on_pushButton_AllStudentInformation_clicked()
{
    this->hide();
    allstudentinformation->show();

}

void Administrator::on_pushButton_AddStudent_clicked()
{
    this->hide();
    addstudent->show();
}

void Administrator::on_pushButton_AllStudentGrades_clicked()
{
    this->hide();
    allstudentgrades->show();

}

void Administrator::on_pushButton_ModifyAdministratorPassword_clicked()
{
    this->hide();
    modifyadministratorpassword->show();

}


void Administrator::on_pushButton_ModifyStudentInformation_clicked()
{
    this->hide();
    modifystudentinformation->show();

}


void Administrator::on_pushButton_ModifyStudentPassword_clicked()
{
    this->hide();
    modifystudentpassword->show();

}


void Administrator::on_pushButton_StudentEpidemicManagement_clicked()
{
    this->hide();
    studentepidemicmanagement->show();
}


void Administrator::on_pushButton_backToThePreviousWindow_clicked()
{
    emit this->backToThePreviousWindow();
}










