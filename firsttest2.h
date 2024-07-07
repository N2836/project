#ifndef FIRSTTEST2_H
#define FIRSTTEST2_H

#include <QMainWindow>
#include "secendtest2.h"
extern QString user;
namespace Ui {
class firsttest2;
}

class firsttest2 : public QMainWindow
{
    Q_OBJECT

public:

    explicit firsttest2(QWidget *parent = nullptr);
    ~firsttest2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::firsttest2 *ui;
};

#endif // FIRSTTEST2_H
