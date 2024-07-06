#include "home.h"
#include "ui_home.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMediaPlayer>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QApplication>
#include<QLabel>
#include <QWidget>
#include <QPixmap>
#include <QFile>
#include <QImage>
#include <QBuffer>

#include "page_search.h"
#include <QIcon>
//#include <QVideoWidget>

extern QString l6;
extern QString user_name;
extern QString user;
QString f;

home::home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
      home::setStyleSheet("background-image: url(:/new/prefix1/background1.jpg);");
     home::isFullScreen();
    /* home::setStyleSheet(
                 "QWidget {background-color: color: blue;}"
                 "QLineEdit, QTabWidget {background-color: none; }"
                 );
*/
    // ui->tabWidget_2->hide();

     //ui->label_6->hide();
     ui->label_7->hide();
    ui->groupBox_3->hide();
    ui->pushButton_5->hide();
    ui->tableView_2->hide();
    ui->groupBox_2->hide();
    ui->tabWidget->setTabText(0,tr("My Network"));
    ui->tabWidget->setTabText(1,tr("Jobs"));
    ui->tabWidget->setTabText(2,tr("Messaging"));
    ui->tabWidget->setTabText(3,tr("Home"));
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("d:\\linkedin2.db");
    if (!database.open()) {
        qDebug() << "Error: Connection with database failed" << database.lastError();
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database");
    } else {
       qDebug() << "Database: Connection ok";
    }
   /* ui->tabWidget->setStyleSheet("QTabWidget::pane { "
                                "background-image: url(:/new/prefix1/background1.jpg); "
                                "background-position: center; "
                                "background-repeat: no-repeat; "
                                "}");
                                */
    ui->tabWidget->setStyleSheet("QTabWidget#tabWidget > QWidget {background-image: url(:/new/prefix1/background1.jpg);}");



}

home::~home()
{
    delete ui;
}



void home::showImagePickerWindow(QLabel *label6) {
    QString fileName = QFileDialog::getOpenFileName(this,
        "انتخاب عکس", "", "تصاویر (*.png *.jpg *.jpeg)");

    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        label6->setPixmap(pixmap);
        label6->setScaledContents(true); // برای تغییر اندازه تصویر به اندازه QLabel
    }
}

void home::showGifPickerWindow(QLabel *label6) {
    QString fileName = QFileDialog::getOpenFileName(this,
        "انتخاب گیف", "", "گیف‌ها (*.gif)");

    if (!fileName.isEmpty()) {
        QMovie *movie = new QMovie(fileName);
        label6->setMovie(movie);
        movie->start();
        label6->setScaledContents(true);
    }
}





/*void home::showVideoPickerWindow(QVideoWidget *videoWidget, QMediaPlayer *mediaPlayer) {
    QString fileName = QFileDialog::getOpenFileName(this,
        "انتخاب ویدیو", "", "ویدیوها (*.mp4 *.avi *.mkv)");

    if (!fileName.isEmpty()) {
        mediaPlayer->setMedia(QUrl::fromLocalFile(fileName));
        mediaPlayer->setVideoOutput(videoWidget);
        mediaPlayer->play();
    }
}
*/

void home::on_pushButton_2_clicked()
{
    search = ui->lineEdit->text();
    QSqlQuery q;

    q.exec("SELECT username FROM linkedin2 WHERE username ='" + search + "'");
    if (q.next()) {
        ui->groupBox_2->show();
        ui->label_8->setText(search);
    } else {
        QMessageBox::warning(this, "", "Not available in the list", "try again");
        ui->groupBox_2->hide();
    }
}

void home::on_pushButton_3_clicked()
{
    page_search *w4 = new page_search;
    w4->show();
      this->close();
}

void home::on_pushButton_4_clicked()
{
    QSqlQuery q;
    q.exec("SELECT companyname, manager, phonnumber, location FROM company WHERE employee_field='" + l6 + "' LIMIT 3");
    QSqlQueryModel *m = new QSqlQueryModel;
    m->setQuery(q);
    ui->tableView->setModel(m);
    ui->pushButton_5->show();
    ui->groupBox_3->show();
}

void home::on_pushButton_5_clicked()
{
    ui->tableView_2->show();
    QSqlQuery p;
    p.exec("SELECT companyname, manager, phonnumber, location FROM company WHERE employee_field='" + l6 + "' LIMIT -1 OFFSET 3");
    QSqlQueryModel *n = new QSqlQueryModel;
    n->setQuery(p);
    ui->tableView_2->setModel(n);
}

void home::on_pushButton_6_clicked()
{
    apply = ui->lineEdit_2->text();
    if (apply.isEmpty()) {
        QMessageBox::warning(this, "", "Please fill in all the blanks", "OK");
        return;
    }
}

void home::on_pushButton_7_clicked()
{
    QSqlQuery query;
    QString name = user;
    query.prepare("UPDATE linkedin2 SET job_applycant= '" + apply + "' WHERE username = '" + name + "'");
    query.bindValue(":username", name);
    query.bindValue(":job_applycant", apply);
}

void home::on_pushButton_8_clicked()
{
    //ui->label_7->hide();
    //ui->label_6->show();
    showImagePickerWindow(ui->label_6);
}

void home::on_pushButton_9_clicked()
{
    //ui->label_6->hide();
   // ui->label_7->show();
    showGifPickerWindow(ui->label_7);
}



void home::on_pushButton_11_clicked()
{






}


void home::on_pushButton_clicked()
{
   //ui->tabWidget_2->show();
}

