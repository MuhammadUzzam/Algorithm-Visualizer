// binary_search.h
#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

namespace Ui {
class binary_search;
}

class searching_window;

class binary_search : public QMainWindow
{
    Q_OBJECT

public:
    explicit binary_search(QMainWindow *parent = nullptr);
    ~binary_search();

private slots:
    void on_btnBacklin_clicked();
    void on_btnResetbin_clicked();
    void on_btnRandomizebin_clicked();
    void on_btnPausebin_clicked();
    void on_btnsearchbin_clicked();
    void nextStep();

private:
    Ui::binary_search *ui;
    searching_window *search_window;
    QGraphicsScene *scene;
    QTimer *timer;
    QList<int> arr;
    int low, high, mid;
    int searchValue;
    bool running, found;

    void generateRandomAndSortArray();
    void drawArray(int low = -1, int high = -1, int mid = -1, bool isFound = false);
    int stepDelayMs() const;
};

#endif // BINARY_SEARCH_H
