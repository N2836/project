#include "yes_click.h"
#include "ui_yes_click.h"
#include "firsttest2.h"
#include "home.h"
#include "home_c.h"
#include <QSqlQuery>
#include "QMessageBox"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QDebug"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "sign_company.h"
#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QSound>
#include <QMediaPlayer>

#include "creat_job.h"
QString pass;

yes_click::yes_click(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::yes_click)
{

    ui->setupUi(this);
    yes_click::setStyleSheet("background-image: url(:/new/prefix1/background1.jpg);");
    yes_click::isFullScreen();
    ui->for_faild->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
      ui->for_password->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
        ui->for_user->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
          ui->pushButton_2->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
          ui->pushButton_3->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
            //ui->pushButton_4->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
              ui->pushButton->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                ui->pushButton_5->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                    ui->lineEdit->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                      ui->lineEdit_2->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
    ui->pushButton_2->hide();
    ui->tabWidget->setTabText(0,tr("company"));
    ui->tabWidget->setTabText(1,tr("Personal"));
    //faild=ui->lineEdit_3->text();
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\linkedin2.db");
    if (!database.open()) {
        qDebug() << "Error: Connection with database failed" << database.lastError();
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database");
    } else {
        qDebug() << "Database: Connection ok";
    }

}

yes_click::~yes_click()
{
    delete ui;
}

void yes_click::on_pushButton_clicked()
{
    home_c *w5 = new home_c;
    w5->show();
      this->close();
}


void yes_click::on_pushButton_2_clicked()
{
    home *w6 = new home;
    w6->show();
      this->close();
}

void yes_click::on_pushButton_3_clicked()
{
    user_name = ui->for_user->text();
    pass=ui->for_password->text();
    //faild=ui->lineEdit_3->text();
    QSqlQuery q;
    //remmeber to fix it
    q.exec("SELECT username FROM linkedin2 WHERE username='"+user_name+"'");
    if (q.next ()){
        QMessageBox::information(this,"","Available in the list","ok");
               ui->pushButton_2->show();

           }
          else {
                 QMessageBox::warning(this,"","Notavailable in the list ","try again");


    }

    }



void yes_click::on_pushButton_5_clicked()
{
   x2= ui->lineEdit->text();
   QString pass=ui->lineEdit_2->text();

   QSqlQuery q;
   //remmeber to fix it
   q.exec("SELECT companyname FROM company WHERE companyname ='"+x2+"'");
   if (q.next ()){
       QMessageBox::information(this,"","Available in the list","ok");
              ui->pushButton_2->show();

          }
         else {
        QSound::play("qrc:/new/prefix1/sound.mp3");
                QMessageBox::warning(this,"","Notavailable in the list ","try again");



   }


}

