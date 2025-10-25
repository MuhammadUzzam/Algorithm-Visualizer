#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <QMainWindow>
class sorting_window;

namespace Ui {
class bubble_sort;
}

class bubble_sort : public QMainWindow
{
    Q_OBJECT

public:
    explicit bubble_sort(QWidget *parent = nullptr);
    ~bubble_sort();

private slots:
    void on_btnBack_clicked();

private:
    Ui::bubble_sort *ui;
    sorting_window* sort_window;

};

#endif // BUBBLE_SORT_H
