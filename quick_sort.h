// quick_sort.h
#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

class sorting_window;

namespace Ui {
class Quick_Sort;
}

class Quick_Sort : public QMainWindow
{
    Q_OBJECT
public:
    explicit Quick_Sort(QWidget *parent = nullptr);
    ~Quick_Sort();

private slots:
    void on_btnReset_clicked();
    void on_btnRandomize_clicked();
    void on_btnPause_clicked();
    void on_btnStart_clicked();
    void on_btnBack_clicked();
    void nextStep();

private:
    Ui::Quick_Sort *ui;
    sorting_window* sort_window;
    QGraphicsScene *scene;
    QTimer *timer;
    QList<int> arr;
    QList<int> tempArr;
    int stepIndex;
    bool running;

    struct Step {
        QList<int> state;
        int pivot;
        int left;
        int right;
    };

    QList<Step> steps;

    void generateRandomArray();
    void recordQuickSort(int left, int right);
    int partition(int left, int right);
    void drawArray(int pivot = -1, int left = -1, int right = -1);
    int stepDelayMs() const;
};
#endif // QUICK_SORT_H
