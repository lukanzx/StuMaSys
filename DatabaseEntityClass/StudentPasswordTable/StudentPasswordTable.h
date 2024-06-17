#ifndef STUDENTPASSWORDTABLE_H
#define STUDENTPASSWORDTABLE_H
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <mutex>
#include <vector>
#include "Global.h"
using std::vector;
class StudentPasswordTable
{
public:
    StudentPasswordTable(const StudentPasswordTable& obj) = delete;
    StudentPasswordTable operator=(const StudentPasswordTable& obj) = delete;

    
    bool VerifyTheUserIdAndPasswordIsCorrect(QString getId,QString getPass);

    
    bool AddOneStudent(QString stid,QString spass);

    
    bool checkStuIdExists(QString stid);

    
    bool SetStudentPassword(QString stid,QString newPass);

    
    bool SetStudentPasswordNeddIdAndOldPass(QString stid,QString oldPass,QString newPass);

    void TestFunction();

    
    QString GetUserId();

    
    QString SetUserId(QString sid);

public:
    static StudentPasswordTable* getInstance();
private:
    StudentPasswordTable() = default;
    QString DatabaseType = "QMYSQL";
    QString DatabaseHostName = "";
    QString DatabaseUseName = "";
    QString DatabaseUserId = "";
    QString DatabasePassword = "";
    QSqlDatabase db;
    QString  UserId;
private:
    static StudentPasswordTable* g_taskQ;
    static std::mutex g_mutex;
};

#endif 
