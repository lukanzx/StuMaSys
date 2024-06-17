#ifndef StudentSelfShowInformation_H
#define StudentSelfShowInformation_H
#include <QWidget>
#include <QPainter>
#include <QString>
#include "StudentGradesTable.h"
#include "StudentHealthSate.h"
#include "StudentPasswordTable.h"
#include "StudentsBasicInformation.h"
#include <vector>
#include "Global.h"
using std::vector;
namespace Ui {
class StudentSelfShowInformation;
}
class StudentSelfShowInformation : public QWidget
{
    Q_OBJECT
public:
    explicit StudentSelfShowInformation(QWidget *parent = 0);
    ~StudentSelfShowInformation();
    void iniScreen();                   
    void paintEvent(QPaintEvent *event);
    void getInformation();              
private slots:
    void on_pushButton_back_clicked();  
signals:
   void backToThePreviousWindow();      
private:
    Ui::StudentSelfShowInformation *ui;
    QString sid;        
    QString ssex;       
    QString sage;       
    QString splace;     
    QString smajor;     
    QString sname;      
};
#endif 
