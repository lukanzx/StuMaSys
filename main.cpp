#include <QApplication>
#include "LogIn.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogIn d;
    d.show();
    return a.exec();
    return 0;
}

