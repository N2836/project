#include "t2.h"
#include "ui_t2.h"
#include "mainsecendtest.h"

T2::T2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::T2)
{
    ui->setupUi(this);

    T2::setStyleSheet("background-image: url(:/new/prefix1/99.jpg);");
     T2::isFullScreen();
}

T2::~T2()
{
    delete ui;
}

void T2::on_pushButton_clicked()
{
    Mainsecendtest *w = new Mainsecendtest;
    w->show();
}

