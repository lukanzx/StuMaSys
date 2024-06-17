#ifndef STUDENTHEALTHSATE_H
#define STUDENTHEALTHSATE_H
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <mutex>
#include "Global.h"
#include <QSqlTableModel>
#include <QSqlQueryModel>
class StudentHealthSate
{
public:
    StudentHealthSate(const StudentHealthSate& obj) = delete;
    StudentHealthSate operator=(const StudentHealthSate& obj) = delete;

    
    void TestFunction();


public:
    static StudentHealthSate* getInstance();
private:
    StudentHealthSate() = default;
    QString DatabaseType = "QMYSQL";
    QString DatabaseHostName = "";
    QString DatabaseUseName = "";
    QString DatabaseUserId = "";
    QString DatabasePassword = "";
    QSqlDatabase db;
    QString  UserId;
private:
    static StudentHealthSate* g_taskQ;
    static std::mutex g_mutex;
};

#endif 
