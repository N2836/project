#ifndef YES_CLICK_H
#define YES_CLICK_H


#include <QMainWindow>
extern QString x2;
extern QString user_name;
//extern QString faild;
namespace Ui {
class yes_click;

}

class yes_click : public QMainWindow
{
    Q_OBJECT

public:
    explicit yes_click(QWidget *parent = nullptr);
    ~yes_click();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::yes_click *ui;
};


#endif // YES_CLICK_H
