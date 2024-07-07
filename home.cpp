#include "home.h"
#include "ui_home.h"
#include "page_search.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QByteArray>
#include <QBuffer>

extern QString l6;
extern QString user_name;
extern QString user;
QString f;
QByteArray byteArray;

home::home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
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

void home::showGifPickerWindow(QLabel *label7)
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open GIF"), "", tr("GIF Files (*.gif)"));
    if (!fileName.isEmpty()) {
        QMovie *movie = new QMovie(fileName);
        if (!movie->isValid()) {
            QMessageBox::warning(this, tr("Error"), tr("The selected file is not a valid GIF."));
            delete movie;
           // label7->setScaledContents(true);
            return;
        }
        movie->setScaledSize(label7->size());
        label7->setMovie(movie);
        movie->start();
    }
}

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
    showImagePickerWindow(ui->label_6);
}

void home::on_pushButton_9_clicked()
{
    showGifPickerWindow(ui->label_7);
}

void home::on_pushButton_11_clicked()
{
    // گرفتن QPixmap از QLabel
    const QPixmap *pixmapPtr = ui->label_6->pixmap();
    if (!pixmapPtr) {
        qDebug() << "No image in the label.";
        return;
    }
    QPixmap pixmap = *pixmapPtr; // تبدیل اشاره‌گر به QPixmap
    qDebug() << "Image successfully retrieved from QLabel.";

    // تبدیل QPixmap به QByteArray
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    if (!pixmap.save(&buffer, "JPG")) {
        qDebug() << "Failed to save pixmap to buffer.";
        return;
    }
    qDebug() << "Pixmap successfully saved to buffer.";

    // اتصال به دیتابیس و ذخیره عکس
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:\\linkedin2.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database fail";
        return;
    } else {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.prepare("UPDATE post SET photo = :photo WHERE username = :username");
    query.bindValue(":username", user);
    query.bindValue(":photo", byteArray);

    if(!query.exec()) {
        qDebug() << "Error: failed to update image in database: " << query.lastError();
    } else {
        qDebug() << "Image updated successfully";
    }

    db.close();
}

void home::on_pushButton_12_clicked()
{
    loadImageFromDatabase();
}

void home::loadImageFromDatabase() {
    // اتصال به دیتابیس
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:\\linkedin2.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database fail";
        return;
    } else {
        qDebug() << "Database: connection ok";
    }

    // اجرای کوئری برای خواندن عکس
    QSqlQuery query;
    query.prepare("SELECT photo FROM post WHERE username = :username");
    query.bindValue(":username", user);

    if (!query.exec()) {
        qDebug() << "Error: failed to fetch image from database: " << query.lastError();
        return;
    }

    if (query.next()) {
        QByteArray byteArray = query.value(0).toByteArray();
        QPixmap pixmap;
        pixmap.loadFromData(byteArray);
        ui->label_6->setPixmap(pixmap);
        ui->label_6->setScaledContents(true);
    } else {
        qDebug() << "No image found for username: " << user;
    }

    db.close();
}
