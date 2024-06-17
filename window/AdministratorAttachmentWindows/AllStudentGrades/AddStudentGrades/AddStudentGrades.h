#ifndef AddStudentGrades_H
#define AddStudentGrades_H
#include <QWidget>
#include "Global.h"
#include <QPainter>
#include <QString>
#include "StudentPasswordTable.h"
#include "StudentGradesTable.h"
namespace Ui {
class AddStudentGrades;
}
class AddStudentGrades : public QWidget
{
    Q_OBJECT
public:
    explicit AddStudentGrades(QWidget *parent = 0);
    ~AddStudentGrades();
    void initScreen();                      
    void paintEvent(QPaintEvent *event);
    bool checkStuId(QString stid);          
    void setGrades();                       
private slots:
    void on_pushButton_back_clicked();      
    void on_lineEdit_stid_editingFinished();
    void on_pushButton_submit_clicked();    
signals:
   void backToThePreviousWindow();          
private:
    Ui::AddStudentGrades *ui;
    QString stid;
    QString english;
    QString math;
    QString cpp;
};
#endif 
