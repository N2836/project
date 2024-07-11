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
#include <QLabel>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QGraphicsVideoItem>
#include <QAbstractVideoSurface>
//#include <qstyleditemdelegate.h>
//#include <QPainter>



/*
class ImageDelegate : public QStyledItemDelegate {
public:
    ImageDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        if (index.column() == 1) { // فرض می‌کنیم ستون عکس ستون دوم است
            QByteArray byteArray = index.data().toByteArray();
            QPixmap pixmap;
            pixmap.loadFromData(byteArray);
            painter->drawPixmap(option.rect, pixmap);
        } else {
            QStyledItemDelegate::paint(painter, option, index);
        }
    }
};

*/



extern QString l6;
extern QString user_name;
extern QString user;
QString f;
QByteArray byteArray;

QString fileName;
extern QString name1;
//extern int sw;
QString A;
QString test;
QString test2;
QString combined;
QByteArray byte;
extern int chek;
extern QString f6;


home::home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    ui->groupBox_3->hide();
    ui->pushButton_5->hide();
    ui->tableView_2->hide();
    ui->groupBox_2->hide();
    ui->tabWidget_2->hide();
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


/*
void home::saveGifToDatabase(const QByteArray& gifData, const QString& username)
{
    // اتصال به دیتابیس اسکیو لایت
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("your_database.db");
    db.open();

    // ذخیره گیف در دیتابیس
    QSqlQuery query;
    query.prepare("INSERT INTO post (gif, user) VALUES (:gif, :user)");
    query.bindValue(":gif", gifData);
    query.bindValue(":user", username);
    if (query.exec()) {
        qDebug() << "GIF saved successfully.";
    } else {
        qDebug() << "Failed to save GIF:" << query.lastError().text();
    }

    db.close();
}
*/




void home::saveGifToDatabase(const QByteArray& gifData, const QString& username)
{
    // اتصال به دیتابیس
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("your_database.db");
    if (!db.open()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open database."));
        return;
    }

    // ذخیره گیف در دیتابیس
    QSqlQuery query;
    query.prepare("INSERT INTO post (gif, user) VALUES (:gif, :user)");
    query.bindValue(":gif", gifData);
    query.bindValue(":user", username);
    if (!query.exec()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to save GIF: ") + query.lastError().text());
    } else {
        QMessageBox::information(this, tr("Success"), tr("GIF saved successfully."));
    }

    db.close();
}



QByteArray home::getGifDataFromSomewhereElse()
{
    // کد برای گرفتن داده گیف از جایی که قبلا ذخیره شده است
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open GIF"), "", tr("GIF Files (*.gif)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            return file.readAll();
        }
    }
    return QByteArray(); // در صورت عدم انتخاب فایل، یک آرایه خالی برمی‌گرداند
}


void home::showImagePickerWindow(QLabel *label6) {
    QString fileName = QFileDialog::getOpenFileName(this,
        "انتخاب عکس", "", "تصاویر (*.png *.jpg *.jpeg)");

    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        label6->setPixmap(pixmap);
        label6->setScaledContents(true); // فیکس کردن اندازه
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
    q.exec("SELECT salary, company, skil, work_place , location_company FROM job WHERE employee_field = '"+l6+"' OR employee_field = '"+f6+"' LIMIT 3");


    QSqlQueryModel *m = new QSqlQueryModel;
    m->setQuery(q);
    ui->tableView->setModel(m);
    ui->pushButton_5->show();
    ui->groupBox_3->show();
    if (name1 == user || name1 == user_name){
        if (chek == 1){
            QMessageBox::information( this , "","You are not accepted" , "ok");
            ui->pushButton_7->setText("apply");
            int num;
            QSqlQuery q;
            q.exec("SELECT employee_number FROM company WHERE companyname = '"+apply+"' ");
            if(q.next()){
                 num = q.value(0).toInt();
            }
         num++;
           QSqlQuery query;
           query.prepare("UPDATE company SET employee_number = :num1 WHERE companyname = :apply");
           query.bindValue(":num1", num);
           query.bindValue(":apply", apply);

        } else if (chek == 2) {
            QMessageBox::information( this , "","You are accepted" , "ok");
            ui->pushButton_7->setText("apply");
        }
    }
}

void home::on_pushButton_5_clicked()
{
    ui->tableView_2->show();
    QSqlQuery p;
   p.exec("SELECT salary, company, skil, work_place , location_company FROM job WHERE employee_field = '"+l6+"' OR employee_field = '"+f6+"' LIMIT -1 OFFSET 3");
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
    ui->pushButton_7->setText("pending");
    QSqlQuery query;

    query.exec("UPDATE linkedin2 SET job_applycant= '" + apply + "' WHERE username = '" + user + "' OR username = '" + user_name + "'");
    //query.bindValue(":username", name);
    //query.bindValue(":job_applycant", apply);
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

void home::on_pushButton_clicked()
{
    ui->tabWidget_2->show();
    QSqlQuery query;
    query.exec("SELECT profile FROM linkedin2 WHERE username = '"+user+"' OR username ='"+user_name+"'");
    if (query.next()) {
        QByteArray imageData = query.value(0).toByteArray();
        QPixmap pixmap;
        pixmap.loadFromData(imageData);
        ui->label_10->setPixmap(pixmap);
        ui->label_10->setScaledContents(true);
        // پرس و جو برای دریافت عکس مربوط به کاربر
        QSqlQuery query;
        query.prepare("SELECT photo FROM post WHERE username = :username");
        query.bindValue(":username", user_name);
        query.exec();

        if (query.next()) {
            // دریافت داده عکس از دیتابیس
            QByteArray imageData = query.value("photo").toByteArray();

            // تبدیل داده عکس به QPixmap و نمایش در لیبل
            QPixmap pixmap;
            pixmap.loadFromData(imageData);
            ui->label_11->setPixmap(pixmap);
            ui->label_11->setScaledContents(true);
        }
    }

}


void home::on_pushButton_16_clicked()
{
     showImagePickerWindow(ui->label_10);
}


void home::on_pushButton_18_clicked()
{

    const QPixmap *pixmapPtr = ui->label_10->pixmap();
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
    if (!pixmap.save(&buffer, "PNG")) {
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
    }
    else {
        qDebug() << "Database: connection ok";
    }

    // ذخیره عکس در جدول linkedin2
    QSqlQuery query;
    query.prepare("UPDATE linkedin2 SET profile = :photo WHERE username = :username OR username = :username2");
    query.bindValue(":photo", byteArray);
    query.bindValue(":username", user);
    query.bindValue(":username2", user_name);
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
    else {
        qDebug() << "Image saved to linkedin2 table successfully.";
    }


    db.close();

}




void home::on_pushButton_19_clicked()
{
    bio=ui->lineEdit_4->text();
        QSqlQuery Q;
        Q.exec("UPDATE linkedin2 SET biography='"+bio+"' WHERE username = '"+user+"' OR username ='"+user_name+"' ");
        //Q.bindValue(":bio", bio);
        //Q.bindValue(":username", user);
        //Q.bindValue(":username2", user_name);


}






void home::on_pushButton_13_clicked() // برای ذخیره گیف
{
    // گرفتن QByteArray از QLabel
    const QPixmap *pixmapPtr = ui->label_7->pixmap();
    if (!pixmapPtr) {
        qDebug() << "No GIF in the label.";
        return;
    }
    QPixmap pixmap = *pixmapPtr; // تبدیل اشاره‌گر به QPixmap

    // تبدیل QPixmap به QByteArray
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    if (!pixmap.save(&buffer, "GIF")) {
        qDebug() << "Failed to save pixmap to buffer.";
        return;
    }
    qDebug() << "Pixmap successfully saved to buffer.";

    // اتصال به دیتابیس و ذخیره گیف
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:\\linkedin2.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database fail";
        return;
    } else {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.prepare("UPDATE post SET gif = :gif WHERE username = :username");
    query.bindValue(":username", user);
    query.bindValue(":gif", byteArray);

    if(!query.exec()) {
        qDebug() << "Error: failed to update GIF in database: " << query.lastError();
    } else {
        qDebug() << "GIF updated successfully";
    }

    db.close();
}

void home::on_pushButton_21_clicked() // برای بارگذاری گیف
{
    loadGifFromDatabase();
}

void home::loadGifFromDatabase() {
    // اتصال به دیتابیس
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:\\linkedin2.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database fail";
        return;
    } else {
        qDebug() << "Database: connection ok";
    }

    // اجرای کوئری برای خواندن گیف
    QSqlQuery query;
    query.prepare("SELECT gif FROM post WHERE username = :username");
    query.bindValue(":username", user);

    if (!query.exec()) {
        qDebug() << "Error: failed to fetch GIF from database: " << query.lastError();
        return;
    }

    if (query.next()) {
        QByteArray byteArray = query.value(0).toByteArray();
        QPixmap pixmap;
        pixmap.loadFromData(byteArray);
        ui->label_7->setPixmap(pixmap);
        ui->label_7->setScaledContents(true);
    } else {
        qDebug() << "No GIF found for username: " << user;
    }

   // db.close();
}








void home::on_pushButton_20_clicked()
{
    // پرس و جو برای دریافت عکس مربوط به کاربر
    QSqlQuery query;
    query.prepare("SELECT photo FROM post WHERE username = :username");
    query.bindValue(":username", user_name);
    query.exec();

    if (query.next()) {
        // دریافت داده عکس از دیتابیس
        QByteArray imageData = query.value("photo").toByteArray();

        // تبدیل داده عکس به QPixmap و نمایش در لیبل
        QPixmap pixmap;
        pixmap.loadFromData(imageData);
        ui->label->setPixmap(pixmap);
        ui->label->setScaledContents(true);
    }

   // db.close();


}


void home::on_pushButton_10_clicked() {
    // باز کردن دیالوگ انتخاب فایل
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Video"), "/", tr("Video Files (*.mp4 *.avi *.mov)"));

    if (!fileName.isEmpty()) {
        qDebug() << "Selected file:" << fileName;

        // ایجاد QMediaPlayer و QVideoWidget به صورت محلی
        QMediaPlayer* player = new QMediaPlayer(this); // یا QScopedPointer<QMediaPlayer> player(new QMediaPlayer(this));
        QVideoWidget* videoWidget = new QVideoWidget(this); // یا QScopedPointer<QVideoWidget> videoWidget(new QVideoWidget(this));

        // تنظیم خروجی ویدیو به ویجت
        player->setVideoOutput(videoWidget);

        // افزودن QVideoWidget به لایوت موجود
        if (ui->verticalLayout) { // اطمینان از وجود verticalLayout
            ui->verticalLayout->addWidget(videoWidget);
        }

        // تنظیم منبع ویدیو و شروع پخش
        player->setMedia(QUrl::fromLocalFile(fileName));
        player->play();

        if (player->state() != QMediaPlayer::PlayingState) {
            qDebug() << "Failed to start playback.";
        }
    } else {
        qDebug() << "No file selected.";
    }
}
