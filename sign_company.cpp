#include "sign_company.h"
#include "ui_sign_company.h"
#include "QString"
#include <QMessageBox>
#include "QMessageBox"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QDebug"
#include "firsttest2.h"
#include "yes_click.h"
#include "home_c.h"
#include "creat_job.h"
//QString x;
//QString y;
//QString z;
sign_company::sign_company(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign_company)
{
    ui->setupUi(this);
    sign_company::setStyleSheet("background-image: url(:/new/prefix1/background1.jpg);");
    sign_company::isFullScreen();
    ui->pushButton->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
      ui->pushButton_2->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
        ui->lineEdit->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
          ui->lineEdit_2->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
          ui->lineEdit_3->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
            ui->lineEdit_4->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
              ui->lineEdit_5->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                ui->lineEdit_6->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\linkedin2.db");
    if (!database.open()) {
        qDebug() << "Error: Connection with database failed" << database.lastError();
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database");
    } else {
        qDebug() << "Database: Connection ok";
    }
}

sign_company::~sign_company()
{
    delete ui;
}

void sign_company::on_pushButton_clicked()
{
    QString y=ui->lineEdit->text();
    QString x1=ui->lineEdit_2->text();
    QString z=ui->lineEdit_3->text();
    QString s=ui->lineEdit_4->text();
    QString l=ui->lineEdit_5->text();
    QString f=ui->lineEdit_6->text();
    if(x1==NULL||y==NULL||z==NULL){
        QMessageBox::warning(this,"","please enter information ","ok");
    }
    if(x1!=NULL&&y!=NULL&&z!=NULL){
        QSqlQuery X;
        X.exec("INSERT INTO company(companyname,username, phonnumber, password,location,field)VALUES('"+y+"','"+x1+"', '"+z+"', '"+s+"','"+l+"','"+f+"')");
    }


}


void sign_company::on_pushButton_2_clicked()
{
    home_c *w6 = new home_c;
    w6->show();
      this->close();
}

