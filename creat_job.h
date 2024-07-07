#ifndef CREAT_JOB_H
#define CREAT_JOB_H

#include <QMainWindow>
extern QString x2;
extern QString x1;
extern QString F;
namespace Ui {
class creat_job;
}

class creat_job : public QMainWindow
{
    Q_OBJECT

public:
    explicit creat_job(QWidget *parent = nullptr);
    ~creat_job();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::creat_job *ui;
};

#endif // CREAT_JOB_H
