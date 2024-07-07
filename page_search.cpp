#include "page_search.h"
#include "ui_page_search.h"
#include "home.h"
extern QString search;
page_search::page_search(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::page_search)
{
    ui->setupUi(this);
    page_search::setStyleSheet("background-image: url(:/new/prefix1/background1.jpg);");
    page_search::isFullScreen();
}

page_search::~page_search()
{
    delete ui;
}
