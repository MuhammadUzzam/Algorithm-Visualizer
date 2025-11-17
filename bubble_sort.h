#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>

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
    void on_btnReset_clicked();
    void on_btnRandomize_clicked();
    void on_btnPause_clicked();
    void on_btnStart_clicked();
    void nextStep();

private:
    Ui::bubble_sort *ui;
    sorting_window* sort_window;
    QGraphicsScene *scene;
    QVector<int> arr;
    QTimer *timer;
    int i, j;
    bool running;

    void drawArray(int highlight1 = -1, int highlight2 = -1);
    void generateRandomArray();
    int stepDelayMs() const;

};

#endif // BUBBLE_SORT_H
