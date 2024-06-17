#ifndef StudentSelfSelectGrades_H
#define StudentSelfSelectGrades_H
#include <QWidget>
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
#include "QPainter"
#include <QString>
namespace Ui {
class StudentSelfSelectGrades;
}
class StudentSelfSelectGrades : public QWidget
{
    Q_OBJECT
public:
    explicit StudentSelfSelectGrades(QWidget *parent = 0);
    ~StudentSelfSelectGrades();
    void initScreen();
    void paintEvent(QPaintEvent *event);
    void getDateAndShow();
    QString convert(float f);
private slots:
    void on_pushButton_back_clicked();
private:
    Ui::StudentSelfSelectGrades *ui;
    QString sid;                
    QString math;               
    QString english;            
    QString cplusplus;          
    QString avgGrade;           
signals:
   void backToThePreviousWindow();
};
#endif 
