#ifndef PAGE_SEARCH_H
#define PAGE_SEARCH_H

#include <QMainWindow>
extern QString search;
namespace Ui {
class page_search;
}

class page_search : public QMainWindow
{
    Q_OBJECT

public:
    explicit page_search(QWidget *parent = nullptr);
    ~page_search();

private:
    Ui::page_search *ui;
};

#endif // PAGE_SEARCH_H
