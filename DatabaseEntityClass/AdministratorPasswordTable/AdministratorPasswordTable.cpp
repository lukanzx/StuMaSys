#include "AdministratorPasswordTable.h"
AdministratorPasswordTable* AdministratorPasswordTable::g_taskQ = nullptr;
std::mutex AdministratorPasswordTable::g_mutex;

AdministratorPasswordTable* AdministratorPasswordTable::getInstance()
{
    if (g_taskQ == nullptr){
        g_mutex.lock();
        if (g_taskQ == nullptr){
           g_taskQ = new AdministratorPasswordTable;
        }
        g_mutex.unlock();
    }
    return g_taskQ;
}
void AdministratorPasswordTable::TestFunction(){
    qDebug()<<"测试成功......\n";
}

bool AdministratorPasswordTable::VerifyTheUserIdAndPasswordIsCorrect(QString getId,QString getPass){
    if (db.isOpen() || !db.isValid() ||db.hostName().isEmpty() ||db.databaseName().isEmpty() ||db.userName().isEmpty() ||db.password().isEmpty()) {
        
        db = QSqlDatabase::addDatabase(DatabaseType);
        db.setHostName(DatabaseHostName);
        db.setDatabaseName(DatabaseUseName);
        db.setUserName(DatabaseUserId);
        db.setPassword(DatabasePassword);
    }
    bool isOpen=db.open();
    if(isOpen){
        QSqlQuery query(db);
        query.exec("select adpass from AdministratorPasswordTable where adid='"+getId+"'");
        query.next();
        QString str=query.value(0).toString();
        str=removeSpace(str);

        qDebug()<<"获取到的密码是："<<str;
        if(str==getPass){
            qDebug()<<"密码正确";
            UserId = getId;
            return true;
        }
        else{
            qDebug()<<"密码错误";
            return false;
        }
    }
    return  false;
}

bool AdministratorPasswordTable::ModifyAdministratorPassword(QString getOldPass, QString newPass){
    if (db.isOpen() || !db.isValid() ||db.hostName().isEmpty() ||db.databaseName().isEmpty() ||db.userName().isEmpty() ||db.password().isEmpty()) {
        
        db = QSqlDatabase::addDatabase(DatabaseType);
        db.setHostName(DatabaseHostName);
        db.setDatabaseName(DatabaseUseName);
        db.setUserName(DatabaseUserId);
        db.setPassword(DatabasePassword);
    }
    bool isOpen=db.open();
    if(isOpen){
        QSqlQuery query(db);
        query.exec("select adpass from AdministratorPasswordTable where adid='"+UserId+"'");
        query.next();
        QString oldP=query.value(0).toString();
        if(oldP==getOldPass){
            query.exec("update AdministratorPasswordTable set adpass ='"+ newPass +"' where adid='"+ UserId +"'");
            query.next();
            return true;
        }
        else{
            return false;
        }
    }
    return  false;
}



























