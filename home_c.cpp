
#include "home_c.h"
#include "ui_home_c.h"
#include "sign_company.h"
#include "home.h"
#include "creat_job.h"

extern QString manger;
extern QString apply;
extern QString F;
home_c::home_c(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home_c)
{
    ui->setupUi(this);
      home_c::setStyleSheet("background-image: url(:/new/prefix1/background1.jpg);");
      home_c::isFullScreen();
       ui->pushButton->setStyleSheet("background-image: url(:/new/prefix1/pushbotton.jpg);color:white;");
    ui->tabWidget->setTabText(0, tr("person"));
    ui->tabWidget->setTabText(1, tr("company"));
}

home_c::~home_c()
{
    delete ui;
}



void home_c::on_pushButton_clicked()
{
    creat_job *w9 = new creat_job;
    w9->show();
      this->close();
}










/*
#include "home_c.h"
#include "ui_home_c.h"
#include "sign_company.h"
#include "home.h"
#include "creat_job.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QMap>
#include <functional>
#include <QDebug>
//#include <QWidget>

extern QString manger;
extern QString apply;
extern QString F;

home_c::home_c(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home_c)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, tr("person"));
    ui->tabWidget->setTabText(1, tr("company"));

    // Call the function to create buttons
    createButtons(); // Assuming you have a QVBoxLayout named verticalLayout in your UI
}

home_c::~home_c()
{
    delete ui;
}

void home_c::createButtons(QVBoxLayout *mainLayout) {
    // اجرای پرس‌وجو SQL
    QSqlQuery query;
    query.prepare("SELECT job_applicant FROM linkedin2 WHERE job_applicant = :searchValue");
    query.bindValue(":searchValue", F);

    // ایجاد یک QGroupBox برای نمایش دکمه‌ها
    QGroupBox *groupBox = new QGroupBox("Applicants", mainLayout->parentWidget());
    QVBoxLayout *layout = new QVBoxLayout(groupBox);

    // ایجاد یک نقشه برای نگهداری اسم‌ها و اشاره‌گرهای تابع
    QMap<QString, std::function<void()>> nameToFunctionMap;

    int count = 0;
    if (query.exec()) {
        while (query.next()) {
            QString name = query.value(0).toString();
            QPushButton *button = new QPushButton(name, groupBox);
            layout->addWidget(button);

            // ایجاد یک تابع برای هر دکمه
            std::function<void()> buttonFunction = [name]() {
                qDebug() << "Button clicked:" << name;
            };
            nameToFunctionMap[name] = buttonFunction;
            QObject::connect(button, &QPushButton::clicked, buttonFunction);

            count++;
        }
        qDebug() << "Number of records with job_applicant equal to" << F << "is:" << count;
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    // ایجاد دکمه‌های اضافی با استفاده از مقدار متغیر count
    for (int i = count; i < 10; i++) {
        QString name = QString("Button %1").arg(i + 1);
        QPushButton *button = new QPushButton(name, groupBox);
        layout->addWidget(button);

        // ایجاد یک تابع برای هر دکمه
        std::function<void()> buttonFunction = [name]() {
            qDebug() << "Button clicked:" << name;
        };
        nameToFunctionMap[name] = buttonFunction;
        QObject::connect(button, &QPushButton::clicked, buttonFunction);
    }

    mainLayout->addWidget(groupBox);
}

void home_c::on_pushButton_clicked()
{
    creat_job *w9 = new creat_job;
    w9->show();
}

*/

