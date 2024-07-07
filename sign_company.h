#ifndef SIGN_COMPANY_H
#define SIGN_COMPANY_H

#include <QMainWindow>
extern QString x1;
namespace Ui {
class sign_company;
}

class sign_company : public QMainWindow
{
    Q_OBJECT

public:
    explicit sign_company(QWidget *parent = nullptr);
    ~sign_company();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sign_company *ui;
};

#endif // SIGN_COMPANY_H
