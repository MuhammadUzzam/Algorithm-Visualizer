#ifndef SORTING_WINDOW_H
#define SORTING_WINDOW_H

#include <QMainWindow>

class MainWindow;
class bubble_sort;
namespace Ui {
class sorting_window;
}

class sorting_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit sorting_window(QWidget *parent = nullptr);
    ~sorting_window();

private slots:
    void on_btnBack_clicked();

    void on_btnBubbleSort_clicked();

private:
    Ui::sorting_window *ui;
    MainWindow* main_window;
    bubble_sort* bubb_sort;
};

#endif // SORTING_WINDOW_H
