#ifndef T1_H
#define T1_H

#include <QMainWindow>

namespace Ui {
class T1;
}

class T1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit T1(QWidget *parent = nullptr);
    ~T1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::T1 *ui;
};

#endif // T1_H
