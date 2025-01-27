
#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QLabel>
#include <QString>
#include <QFileDialog>
#include <QPixmap>
#include <QByteArray>
#include <QBuffer>
#include <QMovie>
#include <QMediaPlayer>
#include <QDebug>
#include <QVideoWidget>

extern QString l6;
extern QString search;
extern QString apply;
extern QString user;
extern QString bio;
extern QString name1;
extern QString f6;
//extern int sw;
extern int chek;

namespace Ui {
class home;
}

class home : public QMainWindow
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked(); // New slot for loading image

    void on_pushButton_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_18_clicked();



    void on_pushButton_19_clicked();

    void on_pushButton_13_clicked();

   void on_pushButton_20_clicked();

   void on_pushButton_21_clicked();

   void on_pushButton_10_clicked();



   void on_pushButton_22_clicked();

  void on_pushButton_23_clicked();

   void on_pushButton_24_clicked();
   void on_pushButton_25_clicked();
   void on_pushButton_26_clicked();
   void on_pushButton_27_clicked();
   void on_pushButton_28_clicked();
   void on_pushButton_29_clicked();
   void on_pushButton_30_clicked();
   void on_pushButton_31_clicked();
   void on_pushButton_32_clicked();
   void on_pushButton_33_clicked();
   void on_pushButton_34_clicked();
   void on_pushButton_35_clicked();
   void on_pushButton_36_clicked();

private:
    Ui::home *ui;
    void showImagePickerWindow(QLabel *label6);
    void showGifPickerWindow(QLabel *label7);
    void loadImageFromDatabase(); // New function for loading image
    void displayImage(QString username,QLabel* label);
    //void saveGifToDatabase(const QByteArray& gifData, const QString& username);
    //QByteArray getGifDataFromPushButton9();
    void saveGifToDatabase(const QByteArray& gifData, const QString& username);
    QByteArray getGifDataFromSomewhereElse();
    void loadGifFromDatabase();

    void showImagePickerWindow2(QLabel *label9);
    void loadImageFromDatabase2();
    void loadImageFromDatabase3();
    void showImagePickerWindow3(QLabel *label13);
    void loadImageFromDatabase4();
    void showImagePickerWindow4(QLabel *label14);
    void showImagePickerWindow5(QLabel *label15);
    void loadImageFromDatabase5();
    void showImagePickerWindow6(QLabel *label16);
 void loadImageFromDatabase6();
};

#endif // HOME_H
