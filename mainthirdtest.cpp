#include "mainthirdtest.h"
#include "ui_mainthirdtest.h"

Mainthirdtest::Mainthirdtest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mainthirdtest)
{
    ui->setupUi(this);
}

Mainthirdtest::~Mainthirdtest()
{
    delete ui;
}
