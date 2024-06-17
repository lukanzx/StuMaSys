#ifndef STUDENTMAIL_H
#define STUDENTMAIL_H

#include <QMainWindow>
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
class StudentMail;
}

class StudentMail : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentMail(QWidget *parent = nullptr);
    ~StudentMail();
signals:
   void backToThePreviousWindow();
private:
    Ui::StudentMail *ui;
};

#endif 
