#include "StudentsBasicInformation.h"
StudentsBasicInformation* StudentsBasicInformation::g_taskQ = nullptr;
std::mutex StudentsBasicInformation::g_mutex;

StudentsBasicInformation* StudentsBasicInformation::getInstance()
{
    if (g_taskQ == nullptr){
        g_mutex.lock();
        if (g_taskQ == nullptr){
           g_taskQ = new StudentsBasicInformation;
        }
        g_mutex.unlock();
    }
    return g_taskQ;
}
void StudentsBasicInformation::TestFunction(){
    qDebug()<<"测试成功......\n";
}
QSqlTableModel* StudentsBasicInformation::ShowInformationTableModel(QWidget* qw){
    QSqlTableModel* model;
    if (db.isOpen() || !db.isValid() ||db.hostName().isEmpty() ||db.databaseName().isEmpty() ||db.userName().isEmpty() ||db.password().isEmpty()) {
        
        db = QSqlDatabase::addDatabase(DatabaseType);
        db.setHostName(DatabaseHostName);
        db.setDatabaseName(DatabaseUseName);
        db.setUserName(DatabaseUserId);
        db.setPassword(DatabasePassword);
    }
    bool isOpen=db.open();
    if(isOpen)
    {
        qDebug()<<"database open success!";
        model = new QSqlTableModel(qw,db);
    }
    return model;
}

bool StudentsBasicInformation::AddOneStudentForInfromation(QString stid,QString sname,QString splace,QString ssex,QString smajor,QString sage){
    if (db.isOpen() || !db.isValid() ||db.hostName().isEmpty() ||db.databaseName().isEmpty() ||db.userName().isEmpty() ||db.password().isEmpty()) {
        
        db = QSqlDatabase::addDatabase(DatabaseType);
        db.setHostName(DatabaseHostName);
        db.setDatabaseName(DatabaseUseName);
        db.setUserName(DatabaseUserId);
        db.setPassword(DatabasePassword);
    }
    bool isOpen=db.open();
    if(isOpen)
    {
        QSqlQuery query(db);
        query.exec("select count(*) from StudentsBasicInformation where stid='"+stid+"'");
        query.next();
        int num;
        num=query.value(0).toInt();
        if(num){
            return false;
        }
        else{
            query.exec("INSERT into StudentsBasicInformation(stid,sname,splace,ssex,smajor,sage) "
                       "values ('"+stid+"','"+sname+"','"+splace+"','"+ssex+"','"+smajor+"','"+sage+"')");
            return true;
        }

    }
    return false;
}


bool StudentsBasicInformation::SetOneStudentForInfromation(QString stid,QString sname,QString splace,QString ssex,QString smajor,QString sage){
    if (db.isOpen() || !db.isValid() ||db.hostName().isEmpty() ||db.databaseName().isEmpty() ||db.userName().isEmpty() ||db.password().isEmpty()) {
        
        db = QSqlDatabase::addDatabase(DatabaseType);
        db.setHostName(DatabaseHostName);
        db.setDatabaseName(DatabaseUseName);
        db.setUserName(DatabaseUserId);
        db.setPassword(DatabasePassword);
    }
    bool isOpen=db.open();
    if(isOpen)
    {
        QSqlQuery query(db);
        query.exec("select count(*) from StudentsBasicInformation where stid='"+stid+"'");
        query.next();
        int num;
        num=query.value(0).toInt();
        if(num){
            return false;
        }
        else{
            query.exec("update StudentsBasicInformation set sname='"+sname+"',ssex='"+ssex+"',sage='"+sage+"',"
                    "splace='"+splace+"',smajor='"+smajor+"' where stid='"+stid+"'");
            query.next();
            return true;
        }
    }
    return false;
}

vector<QString> StudentsBasicInformation::GetStudentInformation(QString sid){
    vector<QString> v;
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
        query.exec("select sname,ssex,sage,splace,smajor from StudentsBasicInformation where stid='"+sid+"'");
        query.next();
        for(int i=0;i<5;i++){
            v.push_back(removeSpace(query.value(0).toString()));
            v.push_back(removeSpace(query.value(1).toString()));
            v.push_back(removeSpace(query.value(2).toString()));
            v.push_back(removeSpace(query.value(3).toString()));
            v.push_back(removeSpace(query.value(4).toString()));
        }
    }
    qDebug()<<"数据库:  v.size:    -->  "<<v.size();
    qDebug()<<"数据库:  v[0]:    -->  "<<v[0];
    qDebug()<<"数据库:  v[1]:    -->  "<<v[1];
    qDebug()<<"数据库:  v[2]:    -->  "<<v[2];
    qDebug()<<"数据库:  v[3]:    -->  "<<v[3];
    qDebug()<<"数据库:  v[4]:    -->  "<<v[4];
    return v;
}























