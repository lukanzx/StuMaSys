#ifndef ModifyStudentPassword_H
#define ModifyStudentPassword_H
#include <QWidget>
#include "Global.h"
#include <QPainter>
#include <QString>
#include "StudentsBasicInformation.h"
#include "StudentPasswordTable.h"
#include <vector>
using std::vector;
namespace Ui {
class ModifyStudentPassword;
}
class ModifyStudentPassword : public QWidget
{
    Q_OBJECT
public:
    explicit ModifyStudentPassword(QWidget *parent = 0);
    ~ModifyStudentPassword();
    void initScreen();
    void paintEvent(QPaintEvent *event);
    void ModifyStudentPasswordFunction(QString stuid,QString getPassword);
private:
    Ui::ModifyStudentPassword *ui;
signals:
    void backToThePreviousWindow();             
private slots:
    void on_pushButton_back_clicked();
    void on_pushButton_submit_clicked();
    void on_lineEdit_stuid_editingFinished();
};
#endif 
