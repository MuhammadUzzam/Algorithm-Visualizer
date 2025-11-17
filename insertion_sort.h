// insertion_sort.h
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

class sorting_window;

namespace Ui {
class Insertion_sort;
}

class Insertion_sort : public QMainWindow
{
    Q_OBJECT
public:
    explicit Insertion_sort(QWidget *parent = nullptr);
    ~Insertion_sort();

private slots:
    void on_btnPause_clicked();
    void on_btnStart_clicked();
    void on_btnRandomize_clicked();
    void on_btnReset_clicked();
    void on_btnBack_clicked();
    void nextStep();

private:
    Ui::Insertion_sort *ui;
    sorting_window* sort_window;
    QGraphicsScene *scene;
    QVector<int> arr;
    QTimer *timer;
    int i, key, j;
    bool running;
    bool inserting;

    void drawArray(int currentIndex = -1, int insertPos = -1, int comparing = -1);
    void generateRandomArray();
    int stepDelayMs() const;
};
#endif // INSERTION_SORT_H
