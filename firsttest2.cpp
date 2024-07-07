#include "firsttest2.h"
#include "ui_firsttest2.h"
#include "yes_click.h"
#include "mainsecendtest.h"
#include "QString"
#include "QMessageBox"
#include <QRandomGenerator>
#include "QString"
#include "QApplication"
#include "QLineEdit"
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QDir"
#include "QInputDialog"
#include "secendtest2.h"
//#include "firsttest2.h"
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QSqlDatabase"
#include "sign_company.h"

#include "QDebug"
int a;
QString b;
QString c;
int sw=-1;
 //QString user;
QString P;
int randomNumber;
firsttest2::firsttest2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::firsttest2)
{
    ui->setupUi(this);
   ui->label_2->hide();
   ui->label_3->hide();
   ui->label_4->hide();
   ui->lineEdit->hide();
   ui->lineEdit_2->hide();
   ui->lineEdit_3->hide();
   ui->pushButton_3->hide();
   ui->pushButton_4->hide();
   ui->pushButton_5->hide();
   ui->pushButton_6->hide();
   ui->label_7->hide();
    firsttest2::setStyleSheet("background-image: url(:/new/prefix1/background1.jpg);");
    firsttest2::isFullScreen();
        ui->pushButton->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
            ui->pushButton_2->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                ui->pushButton_3->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                    ui->pushButton_4->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                        ui->pushButton_5->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                         ui->pushButton_6->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                          ui->pushButton_7->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                           ui->pushButton_8->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                            ui->lineEdit->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                                ui->lineEdit_2->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                                    ui->lineEdit_3->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");

                                    QSqlDatabase database;
                                    database=QSqlDatabase::addDatabase("QSQLITE");
                                    database.setDatabaseName("d:\\linkedin2.db");
                                    database.open();


                                  //  database.transaction();

                                  //  database.commit();

}

firsttest2::~firsttest2()
{
    delete ui;
}

void firsttest2::on_pushButton_2_clicked()
{

    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    ui->lineEdit_3->setReadOnly(true);
    ui->pushButton_6->hide();

}




void firsttest2::on_pushButton_clicked()
{
    yes_click *w3 = new yes_click;
    w3->show();
    //  this->close();
}


void firsttest2::on_pushButton_3_clicked()
{
    int min = 1000;
     int max = 9999;
      randomNumber = QRandomGenerator::global()->bounded(min, max + 1);
     ui->lineEdit_3->setText(QString::number(randomNumber));


}



void firsttest2::on_pushButton_4_clicked()
{
    bool ok;
        int inputNumber = QInputDialog::getInt(this, "Enter Code", "Please enter the code:", 0, 0, 9999, 1, &ok);

        if (ok) {
            if (inputNumber == randomNumber) {

                sw = 0;
            } else {

                sw = 1;
                QMessageBox::warning(this, "Warning", "The code is wrong, please check again", QMessageBox::Ok);
            }
        }
}


void firsttest2::on_pushButton_5_clicked()
{
    user =ui->lineEdit->text();
    P=ui->lineEdit_2->text();
    if(user.isEmpty()){
        QMessageBox::warning(this,"","please enter your username","ok");
    }
    if(P.isEmpty()){
        QMessageBox::warning(this,"","please enter your password","ok");
    }
    if(sw!=0){
        QMessageBox::warning(this,"","please enter captcha","ok");
    }
    ui->pushButton_6->show();

}

void firsttest2::on_pushButton_6_clicked() {
    user=ui->lineEdit->text();
    P=ui->lineEdit_2->text();

    QSqlQuery X;
    X.exec("INSERT INTO linkedin2(username,password)VALUES('"+user+"','"+P+"')");
    QSqlQuery Y;
    Y.exec("INSERT INTO post(username)VALUES('"+user+"')");
    Mainsecendtest *w2 = new Mainsecendtest();
    w2->show();
    //  this->close();
}


void firsttest2::on_pushButton_7_clicked()
{
    sign_company *w7 = new sign_company();
    w7->show();
      //this->close();
}


void firsttest2::on_pushButton_8_clicked()
{
    yes_click *w8 = new yes_click();
    w8->show();
    //  this->close();
}

