#ifndef STUDENTNOTES_H
#define STUDENTNOTES_H

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
class StudentNotes;
}

class StudentNotes : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentNotes(QWidget *parent = nullptr);
    ~StudentNotes();
signals:
   void backToThePreviousWindow();
private:
    Ui::StudentNotes *ui;
};

#endif 
