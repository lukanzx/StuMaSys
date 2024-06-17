#ifndef ModifyAdministratorPassword_H
#define ModifyAdministratorPassword_H
#include <QWidget>
#include "Global.h"
#include <QPAinter>
#include<QString>
#include "AdministratorPasswordTable.h"
namespace Ui {
class ModifyAdministratorPassword;
}
class ModifyAdministratorPassword : public QWidget
{
    Q_OBJECT
public:
    explicit ModifyAdministratorPassword(QWidget *parent = 0);
    ~ModifyAdministratorPassword();
    void initScreen();
    void paintEvent(QPaintEvent *event);
    void modifyPassword(QString getOldPass, QString newPass);   
private slots:
    void on_pushButton_back_clicked();                          
    void on_pushButton_submit_clicked();                        
signals:
    void backToThePreviousWindow();                             
private:
    Ui::ModifyAdministratorPassword *ui;
};
#endif 
