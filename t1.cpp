#include "t1.h"
#include "ui_t1.h"
#include "t2.h"

T1::T1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::T1)
{


    ui->setupUi(this);
    T1::setStyleSheet("background-image: url(:/new/prefix1/99.jpg);");
     T1::isFullScreen();
}

T1::~T1()
{
    delete ui;
}

void T1::on_pushButton_clicked()
{
    T2 *w = new T2;
    w->show();
}

