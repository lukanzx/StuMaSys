
#ifndef StudentFeedback_H
#define StudentFeedback_H
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
#include <QWidget>

namespace Ui {
class StudentFeedback;
}

class StudentFeedback : public QWidget
{
    Q_OBJECT

public:
    explicit StudentFeedback(QWidget *parent = nullptr);
    ~StudentFeedback();
    void iniScreen();
       void paintEvent(QPaintEvent *event);
       void modifyPassword(QString getOldPass, QString newPass);
signals:
   void backToThePreviousWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::StudentFeedback *ui;
};

#endif 
