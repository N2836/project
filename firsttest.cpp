#include "firsttest.h"
#include "ui_firsttest.h"
#include "firsttest2.h"

firsttest::firsttest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::firsttest)
{
    ui->setupUi(this);
    firsttest::setStyleSheet("background-image: url(:/new/prefix1/background1.jpg);");
    firsttest::isFullScreen();
        ui->pushButton->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");

}

firsttest::~firsttest()
{
    delete ui;
}

void firsttest::on_pushButton_clicked()
{
    firsttest2 *w1 = new firsttest2;
    w1->show();
    this->close();
}

