#ifndef ADMINISTRATORPASSWORDTABLE_H
#define ADMINISTRATORPASSWORDTABLE_H
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <mutex>
#include "Global.h"
#include "StudentPasswordTable.h"
class AdministratorPasswordTable
{
public:
    AdministratorPasswordTable(const AdministratorPasswordTable& obj) = delete;
    AdministratorPasswordTable operator=(const AdministratorPasswordTable& obj) = delete;

    
    bool VerifyTheUserIdAndPasswordIsCorrect(QString getId,QString getPass);

    
    bool ModifyAdministratorPassword(QString getOldPass, QString newPass);

    
    void TestFunction();
public:
    static AdministratorPasswordTable* getInstance();
private:
    AdministratorPasswordTable() = default;
    QString DatabaseType = "QMYSQL";
    QString DatabaseHostName = "";
    QString DatabaseUseName = "";
    QString DatabaseUserId = "";
    QString DatabasePassword = "";
    QSqlDatabase db;
    QString  UserId;
private:
    static AdministratorPasswordTable* g_taskQ;
    static std::mutex g_mutex;
};




#endif 

