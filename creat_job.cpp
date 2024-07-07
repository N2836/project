#include "creat_job.h"
#include "ui_creat_job.h"
#include <QString>
#include "home.h"
#include "QMessageBox"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QDebug"
#include "yes_click.h"
#include "sign_company.h"
//QString F;
extern QString x2;
QString D;
 //extern QString F;
extern QString x1;
creat_job::creat_job(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::creat_job)
{
    ui->setupUi(this);

    creat_job::setStyleSheet("background-image: url(:/new/prefix1/background1.jpg);");
    creat_job::isFullScreen();
        ui->pushButton->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
          ui->pushButton_2->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
            ui->lineEdit->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
              ui->lineEdit_2->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                //ui->label->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
                //  ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");


    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\linkedin2.db");
    if (!database.open()) {
        qDebug() << "Error: Connection with database failed" << database.lastError();
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database");
    } else {
        qDebug() << "Database: Connection ok";
    }
}

creat_job::~creat_job()
{
    delete ui;
}
void creat_job::on_pushButton_clicked()
{
    F = ui->lineEdit->text();
    D = ui->lineEdit_2->text();
}

void creat_job::on_pushButton_2_clicked()
{
    if (D.isEmpty() || F.isEmpty()) {
        QMessageBox::warning(this, "", "Please fill in all the blanks", "OK");
        return;
    }

    QString P = x1;
    //QString S = x2;

    QSqlQuery query;
    query.prepare("UPDATE company SET degree = :degree, employee_field = :employee_field WHERE username = :username");
    query.bindValue(":degree", D);
    query.bindValue(":employee_field", F);
    query.bindValue(":username1", P);
    //query.bindValue(":username2", S);

    qDebug() << "Degree: " << D;
    qDebug() << "Employee Field: " << F;
    qDebug() << "Username1: " << P;
   // qDebug() << "Username2: " << S;
    qDebug() << "Executing query: " << query.executedQuery(); // Print the final query

    if (!query.exec()) {
        qDebug() << "Update error:" << query.lastError().text(); // Print detailed error message
    } else {
        QMessageBox::information(this, "", "Data updated successfully", "OK");
    }
}






