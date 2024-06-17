#ifndef StudentSelfModifyPassword_H
#define StudentSelfModifyPassword_H
#include <QWidget>
#include <QPainter>
#include <QString>
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
class StudentSelfModifyPassword;
}
class StudentSelfModifyPassword : public QWidget
{
    Q_OBJECT
public:
    explicit StudentSelfModifyPassword(QWidget *parent = 0);
    ~StudentSelfModifyPassword();
    void iniScreen();                                               
    void paintEvent(QPaintEvent *event);                            
    void modifyPassword(QString getOldPass, QString newPass);       
signals:
   void backToThePreviousWindow();                                  
private slots:
    void on_pushButton_back_clicked();                              
    void on_pushButton_modifyPass_clicked();                        
    void on_lineEdit_newPass_editingFinished();
private:
    Ui::StudentSelfModifyPassword *ui;
    QString sid;                        
};
#endif 
