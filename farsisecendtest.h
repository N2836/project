#ifndef FARSISECENDTEST_H
#define FARSISECENDTEST_H

#include <QMainWindow>

namespace Ui {
class farsisecendtest;
}

class farsisecendtest : public QMainWindow
{
    Q_OBJECT

public:
    explicit farsisecendtest(QWidget *parent = nullptr);
    ~farsisecendtest();

private:
    Ui::farsisecendtest *ui;
};

#endif // FARSISECENDTEST_H
