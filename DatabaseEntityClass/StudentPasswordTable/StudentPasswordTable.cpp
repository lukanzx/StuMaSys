#include "StudentPasswordTable.h"
StudentPasswordTable* StudentPasswordTable::g_taskQ = nullptr;
std::mutex StudentPasswordTable::g_mutex;

StudentPasswordTable* StudentPasswordTable::getInstance()
{
    if (g_taskQ == nullptr){
        g_mutex.lock();
        if (g_taskQ == nullptr){
           g_taskQ = new StudentPasswordTable;
        }
        g_mutex.unlock();
    }
    return g_taskQ;
}
void StudentPasswordTable::TestFunction(){
    qDebug()<<"测试成功......\n";
}



bool StudentPasswordTable::VerifyTheUserIdAndPasswordIsCorrect(QString getId,QString getPass){
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
        query.exec("select spass from StudentPasswordTable where stid='"+getId+"'");
        query.next();
        QString str=query.value(0).toString();
        str=removeSpace(str);

        qDebug()<<"---------------------------------------------";
        qDebug()<<"输入的密码是："<<getPass;
        qDebug()<<"获取的密码是："<<str;
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

bool  StudentPasswordTable::AddOneStudent(QString stid,QString spass){
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
        query.exec("select count(*) from StudentPasswordTable where stid='"+stid+"'");
        query.next();
        int num;
        num=query.value(0).toInt();
        if(num){
            return false;
        }
        else{
            query.exec("insert into StudentPasswordTable(stid,spass)"
                       "values ('"+stid+"','"+spass+"')");
            return true;
        }

    }
    return false;
}

bool StudentPasswordTable::checkStuIdExists(QString stid){
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
        query.exec("select COUNT(stid) from StudentPasswordTable where stid='"+stid+"'");
        query.next();
        int num;
        num=query.value(0).toInt();
        qDebug()<<"num="<<num;
        if(num){
            return true;
        }
        else{
            return false;
        }
    }
    return false;

}


bool StudentPasswordTable::SetStudentPassword(QString stid,QString newPass){
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
        query.exec("update StudentPasswordTable set spass ='"+ newPass +"' where stid='"+ stid +"'");
        query.next();
        return true;
    }
    return false;

}

QString StudentPasswordTable::GetUserId(){
    qDebug()<<"数据库返回的学生的id是: "<<UserId;
    return UserId;
}


bool StudentPasswordTable::SetStudentPasswordNeddIdAndOldPass(QString stid,QString oldPass,QString newPass){
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
        query.exec("select spass from StudentPasswordTable where stid='"+stid +"'");
        query.next();
        QString str=query.value(0).toString();
        str=removeSpace(str);
        if(str==oldPass){
            qDebug()<<"密码正确";
            query.exec("update StudentPasswordTable set spass ='"+ newPass +"' where stid='"+ stid +"'");
            query.next();
            return true;
        }
        else{
            qDebug()<<"密码错误";
            return false;
        }
    }
    return false;
}


QString StudentPasswordTable::SetUserId(QString sid){
    this->UserId=sid;
}


