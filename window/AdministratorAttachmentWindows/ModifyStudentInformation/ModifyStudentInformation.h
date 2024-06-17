#ifndef ModifyStudentInformation_H
#define ModifyStudentInformation_H
#include "StudentsBasicInformation.h"
#include "StudentPasswordTable.h"
#include <QWidget>
#include "Global.h"
#include <QPainter>
#include <QString>
#include <vector>
using std::vector;
namespace Ui {
class ModifyStudentInformation;
}
class ModifyStudentInformation : public QWidget
{
    Q_OBJECT
public:
    explicit ModifyStudentInformation(QWidget *parent = 0);
    ~ModifyStudentInformation();
    void initScreen();
    void paintEvent(QPaintEvent *event);
    void getInfoAndShow();
    void setInformation();
signals:
    void backToThePreviousWindow();                             
private slots:
    void on_pushButton_back_clicked();                          
    void on_comboBox_province_currentIndexChanged(int index);   
    void on_comboBox_province_activated(int index);             
    void on_comboBox_city_activated(const QString &arg1);       
    void on_comboBox_college_currentIndexChanged(int index);    
    void on_pushButton_select_clicked();                        
    void on_comboBox_county_activated(int index);               
    void on_pushButton_clicked();                               
    void on_comboBox_major_activated(int index);                
    void on_comboBox_class_activated(int index);                
private:
    Ui::ModifyStudentInformation *ui;
    QString sid;        
    QString sname;      
    QString ssex;       
    QString splace;     
    QString smajor;     
    QString sage;       
};
#endif 
