#include "StudentNotes.h"
#include "ui_StudentNotes.h"

StudentNotes::StudentNotes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentNotes)
{
    ui->setupUi(this);
}

StudentNotes::~StudentNotes()
{
    delete ui;
}
