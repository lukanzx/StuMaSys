#include "LogIn.h"
#include "ui_LogIn.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>

LogIn::LogIn(QWidget *parent): QMainWindow(parent), ui(new Ui::LogIn)
{
    
    ui->setupUi(this);
    iniScene();
    
    registerTT = new Register;
    retrievepassword = new RetrievePassword;
    
    
    SatelliteWindoweBackTheUpperLevelSignalAndSlotBind();
}


LogIn::~LogIn()
{
    delete ui;
}


void LogIn::iniScene(){
    setFixedSize(500,312);
    setWindowTitle("登陆界面");
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    ui->label_4->setStyleSheet("border :1px ;background-color: rgba(0,0,0,0);color:#00008B");
    ui->label_4->setFont(QFont("Timers",28,QFont::Bold));
};


void LogIn::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0,0,500,312,QPixmap(":/IMG_5867.JPG"));
    /*
        下面应该还会执行父类的paintEvent函数的代码,而并不是到处就结束了
    */

};


void LogIn::SatelliteWindoweBackTheUpperLevelSignalAndSlotBind()
{

    connect(registerTT,&Register::backToThePreviousWindow,[=](){
                    registerTT->hide();
                    this->show();
                }
            );

    connect(retrievepassword,&RetrievePassword::backToThePreviousWindow,[=](){
                    retrievepassword->hide();
                    this->show();
                }
            );

    
}


void LogIn::on_pushButton_log_clicked(){

    
    QString getId=removeSpace(ui->lineEdit_id->text());

    
    QString getPass=removeSpace(ui->lineEdit_password->text());

    qDebug()<<getId<<"\n";
    qDebug()<<getPass<<"\n";

    bool flag_pos;
    
    
    if(ui->radioButton->isChecked()){
        flag_pos=1;
    }
    else{
        flag_pos=0;
    }
    
    bool p = VerifyTheUserIdAndPasswordIsCorrect(flag_pos,getId,getPass);
    if(p && getId != ""){
        qDebug()<<"getId:"<<getId;
        this->hide();
        
        if(flag_pos==1){
            administrator=new Administrator();
            administrator->show();

            
            connect(administrator,&Administrator::backToThePreviousWindow,[=](){
                            this->show();
                            administrator->hide();
                        }
                    );
        }
        else{

            student=new Student();
            student->show();

            connect(student,&Student::backToThePreviousWindow,[=](){
                            this->show();
                            student->hide();
                        }
                    );
        }
        
    }
    else{
        QMessageBox::information(this,"提示","登陆失败,可能的原因:\n  1.账号错误\n  2.密码错误\n若忘记密码，请及时联系学校管理员修改");
    }
    
};



void LogIn::on_pushButton_Register_clicked(){
    this->hide();
    registerTT->show();
};


void LogIn::on_pushButton_RetrievePassword_clicked(){
    this->hide();
    retrievepassword->show();
};

bool LogIn::VerifyTheUserIdAndPasswordIsCorrect(int flag_pos,QString getId,QString getPass){
    
    if(flag_pos == 1){
        bool m = AdministratorPasswordTable::getInstance()->VerifyTheUserIdAndPasswordIsCorrect(getId,getPass);
        return m;
    }
    else{
        bool n = StudentPasswordTable::getInstance()->VerifyTheUserIdAndPasswordIsCorrect(getId,getPass);
        return n;
    }
}











