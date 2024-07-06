#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QLabel>
#include <QFileDialog>
#include <QPixmap>
#include <QMovie>
#include <QMediaPlayer>
//#include <QVideoWidget>
#include <QWidget>
#include <QVBoxLayout>

extern QString l6;
extern QString search;
extern QString apply;
extern QString user;

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
    //void on_pushButton_video_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_clicked();

private:
    Ui::home *ui;
    void showImagePickerWindow(QLabel *label6);
    void showGifPickerWindow(QLabel *label6);
    //void showVideoPickerWindow(QVideoWidget *videoWidget, QMediaPlayer *mediaPlayer);
};

#endif // HOME_H

