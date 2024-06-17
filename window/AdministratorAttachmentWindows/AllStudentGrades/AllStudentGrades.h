#ifndef AllStudentGrades_H
#define AllStudentGrades_H
#include <QWidget>
#include "Global.h"
#include <QPainter>
#include <QSqlQueryModel>
#include "AddStudentGrades.h"
#include <QSortFilterProxyModel>
#include "StudentGradesTable.h"
namespace Ui {
class AllStudentGrades;
}
class AllStudentGrades : public QWidget
{
    Q_OBJECT
public:
    explicit AllStudentGrades(QWidget *parent = 0);
    ~AllStudentGrades();
    void initScreen();
    void paintEvent(QPaintEvent *event);
    void studentGradesView();
private slots:
    void on_comboBox_activated(int index);  
    void on_pushButton_asc_clicked();       
    void on_pushButton_desc_clicked();      
    void on_pushButton_add_clicked();       
    void on_pushButton_refresh_clicked();   
    void on_pushButton_back_clicked();      
signals:
   void backToThePreviousWindow();          
private:
    Ui::AllStudentGrades *ui;
    int num = 0;
    QSqlQueryModel * model;
    AddStudentGrades * addstudentgrades;
    QSortFilterProxyModel * proxyModel;
};
#endif 
