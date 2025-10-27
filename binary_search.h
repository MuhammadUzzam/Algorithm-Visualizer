#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <QMainWindow>
#include <QGraphicsScene> // Graphics ke liye
#include <QTimer>         // Animation ke liye
#include <QVector>        // Array ke liye
#include <algorithm>      // Sorting ke liye

class searching_window; // Assume this is used for the back button

namespace Ui {
class binary_search;
}

class binary_search : public QMainWindow
{
    Q_OBJECT

public:
    // QMainWindow *parent use karna theek hai
    explicit binary_search(QMainWindow *parent = nullptr);
    ~binary_search();

private slots:
    void on_btnsearchbin_clicked();
    void on_btnPausebin_clicked();
    void on_btnRandomizebin_clicked();
    void on_btnResetbin_clicked();
    void on_btnBacklin_clicked();
    void nextStep(); // Binary Search ka har step execute karega

private:
    Ui::binary_search *ui;
    searching_window* search_window = nullptr;

    // Binary Search ke liye zaroori variables
    QGraphicsScene *scene;
    QVector<int> arr;
    QTimer *timer;
    int lowIndex;   // Search range ki shuruaat
    int highIndex;  // Search range ka aakhir
    int midIndex;   // Beech ka index
    int searchValue;
    bool running;
    bool found;

    void drawArray(int low = -1, int high = -1, int mid = -1, bool isFound = false);
    void generateRandomAndSortArray(); // Array banakar sort karega
    int stepDelayMs() const;
};

#endif // BINARY_SEARCH_H
