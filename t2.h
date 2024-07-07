#ifndef T2_H
#define T2_H

#include <QMainWindow>

namespace Ui {
class T2;
}

class T2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit T2(QWidget *parent = nullptr);
    ~T2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::T2 *ui;
};

#endif // T2_H
