#include "mainsecendtest.h"
#include "firsttest.h"
#include <QApplication>
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include "QDir"
#include "QApplication"
#include <QApplication>
#include <QMenuBar>
#include <QWidget>
#include "firsttest2.h"
QString x2;
QString user;
QString user_name;
QString l6;
QString search;
QString x1;
QString apply;
QString F;
//QString faild;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    firsttest w1;
    w1.show();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString databaseName = "D:\\data.db";
    QString relativepath = "data.db";
    QString databaseFilepath = QCoreApplication::applicationDirPath() + QDir::separator() + "data.db";
    db.setDatabaseName(databaseName);
    db.open();
    return a.exec();

}



