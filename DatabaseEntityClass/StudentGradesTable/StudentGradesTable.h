#ifndef STUDENTGRADESTABLE_H
#define STUDENTGRADESTABLE_H
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
#include <vector>
#include "Global.h"
using std::vector;
class StudentGradesTable
{
public:
    StudentGradesTable(const StudentGradesTable& obj) = delete;
    StudentGradesTable operator=(const StudentGradesTable& obj) = delete;

    
    QSqlQueryModel* ShowGradesInformationQueryModel();

    
    bool AddOneStudentGradesAndSetGradesNull(QString stid);

    
    bool AddOneStudentGradesAndSetGradesAndNotNull(QString stid,QString grademath,QString gradeen,QString gradec);

    
    void TestFunction();

    
    vector<QString> GetStudentGrades(QString sid);


public:
    static StudentGradesTable* getInstance();
private:
    StudentGradesTable() = default;
    QString DatabaseType = "QMYSQL";
    QString DatabaseHostName = "";
    QString DatabaseUseName = "";
    QString DatabaseUserId = "";
    QString DatabasePassword = "";
    QSqlDatabase db;
    QString  UserId;
private:
    static StudentGradesTable* g_taskQ;
    static std::mutex g_mutex;
};

#endif 
