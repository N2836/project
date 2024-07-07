#ifndef SECENDTEST2_H
#define SECENDTEST2_H

#include <QMainWindow>
#include "firsttest2.h"
extern QString user ;
extern QString l6;
namespace Ui {
class secendtest2;
}

class secendtest2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit secendtest2(QWidget *parent = nullptr);
    ~secendtest2();
private slots:

void on_pushButton_clicked();
void on_pushButton_2_clicked();

private:
Ui::secendtest2 *ui;
QString username;
};
#endif



