#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include "Global.h"

namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    void iniScene();
    void paintEvent(QPaintEvent *event);
    void getInformation();              
    bool setInformation();              

signals:
    void backToThePreviousWindow();     
private slots:
   void on_pushButton_clicked();
   void on_pushButton_2_clicked();
private:
    Ui::Register *ui;
    QString xeuhao;         
    QString xingming;       
    QString mima;           
};

#endif 
