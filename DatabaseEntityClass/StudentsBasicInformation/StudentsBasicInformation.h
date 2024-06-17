#ifndef STUDENTSBASICINFORMATION_H
#define STUDENTSBASICINFORMATION_H
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <mutex>
#include <QWidget>
#include <QSqlTableModel>
#include <vector>
#include "Global.h"
using std::vector;
class StudentsBasicInformation
{
public:
    StudentsBasicInformation(const StudentsBasicInformation& obj) = delete;
    StudentsBasicInformation operator=(const StudentsBasicInformation& obj) = delete;
    QSqlTableModel* ShowInformationTableModel(QWidget* qw);

    
    bool AddOneStudentForInfromation(QString stid,QString sname,QString splace,QString ssex,QString smajor,QString sage);

    
    bool SetOneStudentForInfromation(QString stid,QString sname,QString splace,QString ssex,QString smajor,QString sage);

    
    vector<QString> GetStudentInformation(QString sid);

    void TestFunction();
public:
    static StudentsBasicInformation* getInstance();
private:
    StudentsBasicInformation() = default;
    QString DatabaseType = "QMYSQL";
    QString DatabaseHostName = "";
    QString DatabaseUseName = "";
    QString DatabaseUserId = "";
    QString DatabasePassword = "";
    QSqlDatabase db;
    QString  UserId;
private:
    static StudentsBasicInformation* g_taskQ;
    static std::mutex g_mutex;
};
#endif 
