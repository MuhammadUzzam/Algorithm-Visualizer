#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

namespace Ui {
class Heap_Sort;
}
class sorting_window;
class Heap_Sort : public QMainWindow
{
    Q_OBJECT
public:
    explicit Heap_Sort(QWidget *parent = nullptr);
    ~Heap_Sort();

private slots:
    void on_btnReset_clicked();
    void on_btnRandomize_clicked();
    void on_btnStart_clicked();
    void on_lineSearchEdit_cursorPositionChanged(int arg1, int arg2);
    void on_btnBack_clicked();
    void on_btninsert_clicked();
    void nextStep();
    void nextAnimationStep();

    void on_btnminheap_clicked();
    void on_btnmaxheap_clicked();

private:
    Ui::Heap_Sort *ui;
    QGraphicsScene *scene;
    sorting_window* sort_window;
    QTimer *timer;
    QList<int> arr;
    QList<QPair<int, int>> swapSteps;
    int stepIndex;
    int animationStep;
    bool running;
    bool isMinHeap;

    void heapify(int n, int i, bool recordSteps = false);
    void heapSort(int n);
    void drawHeapTree(int highlightIdx1 = -1, int highlightIdx2 = -1);
    void drawNode(int idx, int x, int y, int offset, int highlightIdx1 = -1, int highlightIdx2 = -1);
    void generateRandomArray(int size);
    void recordSwap(int i, int j);
};

#endif // HEAP_SORT_H
