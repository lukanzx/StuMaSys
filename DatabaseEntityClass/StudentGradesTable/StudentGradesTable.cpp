#include "StudentGradesTable.h"
StudentGradesTable* StudentGradesTable::g_taskQ = nullptr;
std::mutex StudentGradesTable::g_mutex;

StudentGradesTable* StudentGradesTable::getInstance()
{
    if (g_taskQ == nullptr){
        g_mutex.lock();
        if (g_taskQ == nullptr){
           g_taskQ = new StudentGradesTable;
        }
        g_mutex.unlock();
    }
    return g_taskQ;
}
void StudentGradesTable::TestFunction(){
    qDebug()<<"测试成功......\n";
}

bool StudentGradesTable::AddOneStudentGradesAndSetGradesNull(QString stid){
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
        query.exec("select count(*) from StudentGradesTable where stid='"+stid+"'");
        query.next();
        int num;
        num=query.value(0).toInt();
        if(num){
            return false;
        }
        else{
            query.exec("insert into StudentGradesTable( stid ) values ('"+stid+"')");
            return true;
        }

    }
    return false;
}

QSqlQueryModel* StudentGradesTable::ShowGradesInformationQueryModel(){
    QSqlQueryModel* model = model=new QSqlQueryModel;
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
        
        QString cmd="select StudentsBasicInformation.stid,sname,grademath,gradeen,gradec,gradec+gradeen+grademath from StudentsBasicInformation,StudentGradesTable where StudentsBasicInformation.stid=StudentGradesTable.stid";
        model->setQuery(cmd);
    }
    return model;
}


bool StudentGradesTable::AddOneStudentGradesAndSetGradesAndNotNull(QString stid,QString grademath,QString gradeen,QString gradec){
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
        query.exec("insert into StudentGradesTable(stid,grademath,gradeen,gradec) values ('"+stid+"','"+grademath+"','"+gradeen+"','"+gradec+"')");
        query.next();
        return true;
    }
    return false;
}

vector<QString> StudentGradesTable::GetStudentGrades(QString sid){
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
        query.exec("select * from StudentGradesTable where stid='"+sid+"'");
        query.next();
        for(int i=0;i<5;i++){
            v.push_back(removeSpace(query.value(1).toString()));
            v.push_back(removeSpace(query.value(2).toString()));
            v.push_back(removeSpace(query.value(3).toString()));
            float f = (v[0].toFloat()+v[1].toFloat()+v[2].toFloat())/3;
            QString avg = QString::number(f);
            v.push_back(avg);
        }
    }
    return v;
}














