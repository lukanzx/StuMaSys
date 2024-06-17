
#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>
#include <QPainter>
#include <QString>
#include "Global.h" 
#include "Administrator.h"
#include "Student.h"
#include "Register.h"
#include "RetrievePassword.h"
#include "AdministratorPasswordTable.h"

namespace Ui { class LogIn; }


class LogIn : public QMainWindow
{
    Q_OBJECT
public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();
    void iniScene();
    void paintEvent(QPaintEvent *event);
    void SatelliteWindoweBackTheUpperLevelSignalAndSlotBind();
    bool VerifyTheUserIdAndPasswordIsCorrect(int flag_pos,QString getId,QString getPass);
private slots:
    void on_pushButton_log_clicked();
    void on_pushButton_Register_clicked();          
    void on_pushButton_RetrievePassword_clicked();  
private:
    Ui::LogIn *ui;
    Register* registerTT;               
    RetrievePassword* retrievepassword; 

    Administrator* administrator;       
    Student* student;                   
};
#endif 











