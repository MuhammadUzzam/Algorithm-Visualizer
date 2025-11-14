//merge_sort.h
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

    namespace Ui {
    class Merge_sort;
}

class Merge_sort : public QMainWindow
{
    Q_OBJECT

public:
    explicit Merge_sort(QWidget *parent = nullptr);
    ~Merge_sort();

private slots:
    void on_btnStart_clicked();
    void on_btnPause_clicked();
    void on_btnReset_clicked();
    void on_btnRandomize_clicked();
    void on_btnBack_clicked();
    void nextStep();

private:
    Ui::Merge_sort *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QList<int> arr;
    QList<int> tempArr;
    int stepIndex;
    bool running;

    struct Step {
        QList<int> state;
        int left, right;
    };
    QList<Step> steps;

    void generateRandomArray();
    void recordMergeSort(int left, int right);
    void merge(int left, int mid, int right);
    void drawArray(int left = -1, int right = -1);
    int stepDelayMs() const;
};

#endif
