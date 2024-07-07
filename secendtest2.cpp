#include "secendtest2.h"
#include "ui_secendtest2.h"
#include "QString"
#include "QMessageBox"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QDebug"
#include "home.h"
#include "firsttest2.h"
QString l2;
QString l3;
QString l4;
QString l5;
//QString l6;

QString c2;
QString c3;
QString c4;
extern QString user;


secendtest2::secendtest2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secendtest2)
{
    ui->setupUi(this);

    secendtest2::isFullScreen();
    secendtest2::setStyleSheet("background-image: url(:/new/prefix1/999.jpg);");
    ui->pushButton->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
    ui->pushButton_2->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
    ui->lineEdit_2->setStyleSheet("background-image: url(:/new/prefix1/white.jpg);");
    ui->lineEdit_3->setStyleSheet("background-image: url(:/new/prefix1/white.jpg);");
    ui->lineEdit_4->setStyleSheet("background-image: url(:/new/prefix1/white.jpg);");
    ui->lineEdit_5->setStyleSheet("background-image: url(:/new/prefix1/white.jpg);");
    ui->lineEdit_6->setStyleSheet("background-image: url(:/new/prefix1/white.jpg);");

    QStringList years = {"", "2004", "2003", "2002", "2001", "2000", "1999", "1998", "1997", "1996", "1995", "1994", "1993", "1992", "1991", "1990", "1989", "1988", "1987", "1986", "1985", "1984", "1983", "1982", "1981", "1980"};
    ui->comboBox_2->addItems(years);

    QStringList months = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    ui->comboBox_3->addItems(months);

    QStringList days = {"", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
    ui->comboBox_4->addItems(days);

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\linkedin2.db");
    if (!database.open()) {
        qDebug() << "Error: Connection with database failed" << database.lastError();
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database");
    } else {
        qDebug() << "Database: Connection ok";
    }
}

secendtest2::~secendtest2()
{
    delete ui;
}

void secendtest2::on_pushButton_clicked()
{

    //QSqlQuery q;
    l2 = ui->lineEdit_2->text();
    l3 = ui->lineEdit_3->text();
    l4 = ui->lineEdit_4->text();
    l5 = ui->lineEdit_5->text();
    l6 = ui->lineEdit_6->text();

    c2 = ui->comboBox_2->currentText();
    c3 = ui->comboBox_3->currentText();
    c4 = ui->comboBox_4->currentText();

   // q.exec("INSERT INTO linkedin2(day, month, year, job, post, place, degree, field)VALUES('"+c4+"','"+c3+"','"+c2+"','"+l2+"','"+l3+"','"+l4+"','"+l5+"','"+l6+"')");

}

void secendtest2::on_pushButton_2_clicked()
{

    if (l2.isEmpty() || l3.isEmpty() || l4.isEmpty() || l5.isEmpty() || l6.isEmpty() || c2.isEmpty() || c3.isEmpty() || c4.isEmpty()) {
        QMessageBox::warning(this, "", "Please fill in all the blanks", "OK");
        return;
    }
    QString P = user;
qDebug ()<<user;
    QSqlQuery query;
      //  query.prepare("UPDATE  linkedin2 SET (day, month, year, job, post, place, degree, field) VALUES(':','"+c3+"','"+c2+"','"+l2+"','"+l3+"','"+l4+"','"+l5+"','"+l6+"') WHERE username = '"+P+"' ");

  query.prepare("  UPDATE  linkedin2 SET day= '"+c4+"',month='"+c3+"',year = '"+c2+"',job='"+l2+"',post='"+l3+"',place='"+l4+"',degree='"+l5+"',field='"+l6+"' WHERE username = '"+P+"'");


//        query.bindValue(":password", P);

//        query.bindValue(":day", c4);
//        query.bindValue(":month", c3);
//        query.bindValue(":year", c2);
//        query.bindValue(":job", l2);
//        query.bindValue(":post", l3);
//        query.bindValue(":place", l4);
//        query.bindValue(":degree", l5);
//        query.bindValue(":field", l6);

    if (!query.exec()) {
        qDebug() << "Insert error:" << query.lastError();
    } else {
        QMessageBox::information(this, "", "Data inserted successfully", "OK");
    }
   home *w4 = new home;
    w4->show();
      this->close();
}
