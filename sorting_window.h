#ifndef SORTING_WINDOW_H
#define SORTING_WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

class MainWindow;
class bubble_sort;
class Selection_sort;
class Heap_Sort;
class Merge_sort;
class Insertion_sort;
class Quick_Sort;
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

    void on_btnselectionSort_clicked();

    void on_btnmergeSort_clicked();

    void on_btnheapSort_clicked();

    void on_btnInsertionSort_clicked();

    void on_btnsquickSort_3_clicked();

private:
    Ui::sorting_window *ui;
    MainWindow* main_window;
    bubble_sort* bubb_sort;
    Selection_sort* select_sort;
    Insertion_sort* insertion_sort;
    Merge_sort* merge_sort;
    Heap_Sort* heap_sort;
    Quick_Sort* quick_sort;
};
#endif // SORTING_WINDOW_H
