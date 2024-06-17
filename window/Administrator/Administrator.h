#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <QWidget>
#include <QPainter>
#include <QMainWindow>
#include "AllStudentInformation.h"
#include "AddStudent.h"
#include "ModifyStudentPassword.h"
#include "ModifyAdministratorPassword.h"
#include "AllStudentGrades.h"
#include "ModifyStudentInformation.h"
#include "StudentEpidemicManagement.h"
namespace Ui {
    class Administrator;
}

class Administrator : public QMainWindow
{
    Q_OBJECT
public:
    explicit Administrator(QWidget *parent = nullptr);
    ~Administrator();
    void iniScene();                                            
    void paintEvent(QPaintEvent *event);                        
    void SatelliteWindoweBackTheUpperLevelSignalAndSlotBind();  
private slots:
    
    void on_pushButton_AllStudentInformation_clicked();         
    void on_pushButton_AddStudent_clicked();                    
    void on_pushButton_AllStudentGrades_clicked();              
    void on_pushButton_ModifyAdministratorPassword_clicked();   
    void on_pushButton_ModifyStudentInformation_clicked();      
    void on_pushButton_ModifyStudentPassword_clicked();         
    void on_pushButton_StudentEpidemicManagement_clicked();     
    
    void on_pushButton_backToThePreviousWindow_clicked();

signals:
     void backToThePreviousWindow();                            
private:
    Ui::Administrator *ui;
    
    
    AllStudentInformation * allstudentinformation;              
    AddStudent * addstudent;                                    
    AllStudentGrades * allstudentgrades;                        
    ModifyAdministratorPassword * modifyadministratorpassword;  
    ModifyStudentInformation * modifystudentinformation;        
    ModifyStudentPassword * modifystudentpassword;              
    StudentEpidemicManagement * studentepidemicmanagement;      
    
};
#endif 














