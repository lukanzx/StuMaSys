#ifndef STUDENT_H
#define STUDENT_H
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "StudentSelfModifyPassword.h"
#include "StudentSelfSelectGrades.h"
#include "StudentSelfShowInformation.h"
#include "StudentHealth.h"
#include "StudentNotes.h"
#include "StudentMail.h"
#include "StudentFeedback.h"
#include "Global.h"
namespace Ui {
    class Student;
}
class Student : public QMainWindow
{
    Q_OBJECT
public:
    explicit Student(QWidget *parent = nullptr);
    ~Student();
    void initScreen();                                          
    void paintEvent(QPaintEvent *event);                        
    void SatelliteWindoweBackTheUpperLevelSignalAndSlotBind();  
private slots:
    
    void on_pushButton_StudentSelfShowInformation_clicked();    
    void on_pushButton_StudentSelfModifyPassword_clicked();     
    void on_pushButton_StudentHealth_clicked();                 
    void on_pushButton_StudentNotes_clicked();                  
    void on_pushButton_StudentSelfSelectGrades_clicked();       
    void on_pushButton_StudentMail_clicked();                   
    void on_pushButton_StudentFeedback_clicked();               
    
    void on_pushButton_backToThePreviousWindow_clicked();

signals:
    void backToThePreviousWindow();
private:
    Ui::Student *ui;

    StudentSelfShowInformation* studentselfshowinformation;
    StudentSelfModifyPassword* studentselfmodifypassword;
    StudentHealth* studenthealth;
    StudentNotes* studentnotes;
    StudentSelfSelectGrades* studentselfselectgrades;
    StudentMail* studentmail;
    StudentFeedback* studentfeedback;
};

#endif 

