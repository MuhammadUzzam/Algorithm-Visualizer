#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>

class sorting_window;

namespace Ui {
class Selection_sort;
}

class Selection_sort : public QMainWindow
{
    Q_OBJECT

public:
    explicit Selection_sort(QWidget *parent = nullptr);
    ~Selection_sort();

private slots:
    void on_btnBack_clicked();
    void on_btnStart_clicked();
    void on_btnReset_clicked();
    void on_btnRandomize_clicked();
    void on_btnPause_clicked();
    void nextStep();

private:
    Ui::Selection_sort *ui;
    sorting_window* sort_window;
    QGraphicsScene *scene;
    QVector<int> arr;
    QTimer *timer;
    int i, j, minIndex;
    bool running;
    bool swapping;

    void drawArray(int currentIndex = -1, int minIndex = -1, int comparing = -1);
    void generateRandomArray();
    int stepDelayMs() const;
};

#endif // SELECTION_SORT_H
