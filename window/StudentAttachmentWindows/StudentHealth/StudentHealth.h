#ifndef StudentHealth_H
#define StudentHealth_H
#include <QWidget>
#include <QPainter>
#include <QString>
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
#include <QPainter>
namespace Ui {
class StudentHealth;
}

class StudentHealth : public QWidget
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent *event);
    explicit StudentHealth(QWidget *parent = nullptr);
    ~StudentHealth();

    
    void initScreen();

    
    bool checkStuId(QString stid);

    
    void setHealthCPdeState();

private slots:
    void on_pushButton_back_clicked();
    void on_pushButton_add_clicked();
signals:
   void backToThePreviousWindow();
private:
    Ui::StudentHealth *ui;
    QString stid;
    QString BodyTemperature;
    QString HealthCode;
};

#endif 
