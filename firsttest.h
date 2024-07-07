#ifndef FIRSTTEST_H
#define FIRSTTEST_H

#include <QMainWindow>

namespace Ui {
class firsttest;
}

class firsttest : public QMainWindow
{
    Q_OBJECT

public:
    explicit firsttest(QWidget *parent = nullptr);
    ~firsttest();

private slots:
    void on_pushButton_clicked();

private:
    Ui::firsttest *ui;
};

#endif // FIRSTTEST_H
