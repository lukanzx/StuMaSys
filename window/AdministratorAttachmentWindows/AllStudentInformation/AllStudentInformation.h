#ifndef AllStudentInformation_H
#define AllStudentInformation_H
#include <QWidget>
#include "Global.h"
#include <QSqlTableModel>
#include <QPainter>
#include "StudentsBasicInformation.h"
namespace Ui {
class AllStudentInformation;
}
class AllStudentInformation : public QWidget
{
    Q_OBJECT
public:
    explicit AllStudentInformation(QWidget *parent = 0);
    ~AllStudentInformation();
    void initScreen();                          
    void studentInfoView();                     
    void paintEvent(QPaintEvent *event);        
private slots:
    void on_pushButton_refresh_clicked();       
    void on_pushButton_cancel_clicked();        
    void on_pushButton_add_clicked();           
    void on_pushButton_delete_clicked();        
    void on_pushButton_asc_clicked();           
    void on_pushButton_desc_clicked();          
    void on_pushButton_back_clicked();          
signals:
    void backToThePreviousWindow();             
private:
    Ui::AllStudentInformation *ui;
    QSqlTableModel * model;
};
#endif 
