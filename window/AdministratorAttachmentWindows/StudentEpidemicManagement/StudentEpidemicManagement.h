#ifndef StudentEpidemicManagement_H
#define StudentEpidemicManagement_H
#include <QWidget>
#include "Global.h"
#include <QPainter>
#include <QString>
#include <QWidget>
#include <QPainter>
#include "StudentHealthSate.h"
#include "StudentGradesTable.h"
#include "StudentPasswordTable.h"
#include "StudentsBasicInformation.h"
namespace Ui {
class StudentEpidemicManagement;
}

class StudentEpidemicManagement : public QWidget
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent *event);
    explicit StudentEpidemicManagement(QWidget *parent = nullptr);
    ~StudentEpidemicManagement();
    void initScreen();
    bool checkStuId(QString stid);
    void SetHealthCodeState();

private slots:
    void on_pushButton_back_clicked();
    void on_pushButton_submit22_clicked();

signals:
    void backToThePreviousWindow();     
private:
    Ui::StudentEpidemicManagement *ui;
    QString stid;
    QString BodyTemperature;
    QString HealthCode;
};
#endif 
