#include "AddStudent.h"
#include "ui_AddStudent.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>

AddStudent::AddStudent(QWidget *parent) :QWidget(parent),ui(new Ui::AddStudent)
{
    ui->setupUi(this);
    initScreen();
}


AddStudent::~AddStudent()
{
    delete ui;
}


void AddStudent::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,500,333,QPixmap(":/IMG_5857.JPG"));
}


void AddStudent::initScreen()
{
    setWindowIcon(QIcon(":/imag/icon.jpg"));
    setFixedSize(500,333);
    setWindowTitle("添加学生信息");
    ui->comboBox_province->setCurrentIndex(1);
    ui->comboBox_college->setCurrentIndex(1);
}


void AddStudent::getInformation()
{
    sname=removeSpace(ui->lineEdit_name->text());
    sid=removeSpace(ui->lineEdit_id->text());
    spass=removeSpace(ui->lineEdit_pass->text());
    sage=removeSpace(ui->lineEdit_age->text());
    if(ui->radioButton_man->isChecked()){
        ssex="男";
    }
    else if(ui->radioButton_woman->isChecked()){
        ssex="女";
    }

    splace=ui->comboBox_province->currentText()+ui->comboBox_city->currentText()+ui->comboBox_county->currentText();
    smajor=ui->comboBox_college->currentText()+ui->comboBox_major->currentText()+ui->comboBox_class->currentText();

    qDebug()<<sname<<sid<<spass<<ssex<<splace<<smajor;
}


bool AddStudent::setInformation()
{
    
    bool m = StudentPasswordTable::getInstance()->AddOneStudent(sid,spass);

    
    bool n = StudentsBasicInformation::getInstance()->AddOneStudentForInfromation(sid,sname,splace,ssex,smajor,sage);

    
    bool f =  StudentGradesTable::getInstance()->AddOneStudentGradesAndSetGradesNull(sid);

    if(m == false || n == false || f == false){
        QMessageBox::critical(this,"警告","添加失败,可能此学生已经存在!\n请重新输入");
        return false;
    }
    else{
        QMessageBox::information(this,"提示","添加学生成功");
        return true;
    }
}


void AddStudent::on_pushButton_submit_clicked()
{
    getInformation();
    
    if(isProperId(sid)){
        qDebug()<<"账号格式正确";
        if(sid !="" && isProperPassword(spass) && spass != ""){
            setInformation();
        }
        else{
            QMessageBox::critical(this,"警告","添加失败！\n账号，密码，姓名三项不能为空!");
        }
    }
    else{
        QMessageBox::critical(this,"警告","学号格式错误");
    }
}


void AddStudent::on_pushButton_back_clicked()
{
    emit this->backToThePreviousWindow(); 
}


void AddStudent::on_comboBox_province_currentIndexChanged(int index)
{
    switch(ui->comboBox_province->currentIndex())
    {
    case 0:
        ui->comboBox_city->clear();
        ui->comboBox_city->insertItem(0,"成都市");
        ui->comboBox_city->insertItem(1,"德阳市");
        ui->comboBox_city->insertItem(2,"绵阳市");
        ui->comboBox_city->insertItem(3,"宜宾市");
        ui->comboBox_city->insertItem(4,"乐山市");
        ui->comboBox_city->insertItem(5,"巴中市");
        ui->comboBox_city->insertItem(6,"遂宁市");
        break;
    case 1:
        ui->comboBox_city->clear();
        ui->comboBox_city->insertItem(0,"朝阳区");
        ui->comboBox_city->insertItem(1,"东城区");
        ui->comboBox_city->insertItem(2,"西城区");
        ui->comboBox_city->insertItem(3,"房山区");
        ui->comboBox_city->insertItem(4,"密云区");
        ui->comboBox_city->insertItem(5,"海淀区");
        break;
    case 2:
        ui->comboBox_city->clear();
        ui->comboBox_city->insertItem(0,"黄浦区");
        ui->comboBox_city->insertItem(1,"松江区");
        ui->comboBox_city->insertItem(2,"浦东新区");
        ui->comboBox_city->insertItem(3,"宝山区");
        ui->comboBox_city->insertItem(4,"长宁区");
        ui->comboBox_city->insertItem(5,"静安区");
        break;
    case 3:
        ui->comboBox_city->clear();
        ui->comboBox_city->insertItem(0,"南宁市");
        ui->comboBox_city->insertItem(1,"柳州市");
        ui->comboBox_city->insertItem(2,"桂林市");
        break;
    case 4:
        ui->comboBox_city->clear();
        ui->comboBox_city->insertItem(0,"广州市");
        ui->comboBox_city->insertItem(1,"深圳市");
        ui->comboBox_city->insertItem(2,"珠海市");
        ui->comboBox_city->insertItem(3,"汕头市");
        break;
    }
}


void AddStudent::on_comboBox_city_activated(const QString &arg1)
{
    if(arg1=="成都市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"郫都区");
        ui->comboBox_county->insertItem(1,"青羊区");
        ui->comboBox_county->insertItem(2,"都江堰市");
        ui->comboBox_county->insertItem(3,"双流区");
    }
    else if(arg1=="德阳市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"旌阳区");
        ui->comboBox_county->insertItem(1,"罗江区");
        ui->comboBox_county->insertItem(2,"广汉市");
        ui->comboBox_county->insertItem(3,"中江县");
    }
    else if(arg1=="绵阳市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"游仙区");
        ui->comboBox_county->insertItem(1,"三台县");
        ui->comboBox_county->insertItem(2,"盐亭县");
        ui->comboBox_county->insertItem(3,"平武县");
    }
    else if(arg1=="宜宾市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"翠屏区");
        ui->comboBox_county->insertItem(1,"宜宾县");
        ui->comboBox_county->insertItem(2,"南溪区");
    }
    else if(arg1=="乐山市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"市中区");
        ui->comboBox_county->insertItem(1,"五通桥区");
        ui->comboBox_county->insertItem(2,"峨眉山市");
    }
    else if(arg1=="巴中市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"巴州区");
        ui->comboBox_county->insertItem(1,"恩阳区");
        ui->comboBox_county->insertItem(2,"平昌县");
    }
    else if(arg1=="遂宁市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"船山区");
        ui->comboBox_county->insertItem(1,"射洪县");
        ui->comboBox_county->insertItem(2,"大英县");
    }
    else if(arg1=="南宁市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"兴宁区");
        ui->comboBox_county->insertItem(1,"江南区");
        ui->comboBox_county->insertItem(2,"横县");
    }
    else if(arg1=="柳州市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"柳州区");
        ui->comboBox_county->insertItem(1,"柳北区");
        ui->comboBox_county->insertItem(2,"柳中区");
    }
    else if(arg1=="桂林市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"秀峰区");
        ui->comboBox_county->insertItem(1,"叠彩区");
        ui->comboBox_county->insertItem(2,"七星区");
    }
    else if(arg1=="广州市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"花都区");
        ui->comboBox_county->insertItem(1,"越秀区");
        ui->comboBox_county->insertItem(2,"白云区");
    }
    else if(arg1=="深圳市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"宝安区");
        ui->comboBox_county->insertItem(1,"罗湖区");
        ui->comboBox_county->insertItem(2,"南山区");
    }
    else if(arg1=="珠海市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"香洲区");
        ui->comboBox_county->insertItem(1,"斗门区");
    }
    else if(arg1=="汕头市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"金平区");
        ui->comboBox_county->insertItem(1,"龙湖区");
    }
    else{
        ui->comboBox_county->clear();
    }

}


void AddStudent::on_comboBox_province_activated(int index)
{
    QString getcity=ui->comboBox_city->currentText();
    if(getcity=="成都市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"郫都区");
        ui->comboBox_county->insertItem(1,"青羊区");
        ui->comboBox_county->insertItem(2,"都江堰市");
        ui->comboBox_county->insertItem(3,"双流区");
    }
    else if(getcity=="南宁市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"兴宁区");
        ui->comboBox_county->insertItem(1,"江南区");
        ui->comboBox_county->insertItem(2,"横县");
    }
    else if(getcity=="广州市"){
        ui->comboBox_county->clear();
        ui->comboBox_county->insertItem(0,"花都区");
        ui->comboBox_county->insertItem(1,"越秀区");
        ui->comboBox_county->insertItem(2,"白云区");
    }
    else{
        ui->comboBox_county->clear();
    }
}


void AddStudent::on_comboBox_college_currentIndexChanged(int index)
{
    switch(ui->comboBox_college->currentIndex())
    {
    case 0:
        ui->comboBox_major->clear();
        ui->comboBox_major->insertItem(0,"思想政治教育");
        break;
    case 1:
        ui->comboBox_major->clear();
        ui->comboBox_major->insertItem(0,"会计学");
        ui->comboBox_major->insertItem(1,"人力资源管理");
        ui->comboBox_major->insertItem(2,"物流工程");
        ui->comboBox_major->insertItem(3,"市场营销");
        ui->comboBox_major->insertItem(4,"工商管理");
        ui->comboBox_major->insertItem(5,"资产评估");
        ui->comboBox_major->insertItem(6,"财务管理");
        break;
    case 2:
        ui->comboBox_major->clear();
        ui->comboBox_major->insertItem(0,"计算机科学与技术");
        ui->comboBox_major->insertItem(1,"软件工程");
        ui->comboBox_major->insertItem(2,"物联网工程");
        ui->comboBox_major->insertItem(3,"信息安全");
        break;
    case 3:
        ui->comboBox_major->clear();
        ui->comboBox_major->insertItem(0,"信息与计算科学");
        ui->comboBox_major->insertItem(1,"化学");
        ui->comboBox_major->insertItem(2,"应用物理学");
        break;
    case 4:
        ui->comboBox_major->clear();
        ui->comboBox_major->insertItem(0,"英语");
        ui->comboBox_major->insertItem(1,"翻译");
        ui->comboBox_major->insertItem(2,"日语");
        break;

    }
}

