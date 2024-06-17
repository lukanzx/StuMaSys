#ifndef AddStudent_H
#define AddStudent_H
#include <QWidget>
#include "Global.h"
#include <QPainter>
#include "StudentPasswordTable.h"
#include "StudentsBasicInformation.h"
#include "StudentGradesTable.h"
#include <QMessageBox>
namespace Ui {
class AddStudent;
}
class AddStudent : public QWidget
{
    Q_OBJECT
public:
    explicit AddStudent(QWidget *parent = 0);
    ~AddStudent();
    void paintEvent(QPaintEvent *event);
    void initScreen();                                  
    void getInformation();                              
    bool setInformation();                              
private slots:
    void on_comboBox_province_currentIndexChanged(int index);
    void on_pushButton_back_clicked();                  
    void on_pushButton_submit_clicked();                
    void on_comboBox_college_currentIndexChanged(int index);
    void on_comboBox_city_activated(const QString &arg1);
    void on_comboBox_province_activated(int index);
signals:
   void backToThePreviousWindow();                      
private:
    Ui::AddStudent *ui;
    QString sname;      
    QString sid;        
    QString splace;     
    QString smajor;     
    QString ssex;       
    QString sage;       
    QString spass;      
};
#endif 
