#include "farsisecendtest.h"
#include "ui_farsisecendtest.h"

farsisecendtest::farsisecendtest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::farsisecendtest)
{
    ui->setupUi(this);
}

farsisecendtest::~farsisecendtest()
{
    delete ui;
}
