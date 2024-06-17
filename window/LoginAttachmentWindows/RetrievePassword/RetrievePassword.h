
#ifndef RETRIEVEPASSWORD_H
#define RETRIEVEPASSWORD_H

#include <QMainWindow>
#include "Global.h"
namespace Ui {
class RetrievePassword;
}

class RetrievePassword : public QMainWindow
{
    Q_OBJECT

public:
    explicit RetrievePassword(QWidget *parent = nullptr);
    ~RetrievePassword();
    void iniScene();
    void paintEvent(QPaintEvent *event);

signals:
    void backToThePreviousWindow();         
private slots:
   void on_pushButton_back_clicked();
   void on_pushButton_submit_clicked();

private:
    Ui::RetrievePassword *ui;
};

#endif 
