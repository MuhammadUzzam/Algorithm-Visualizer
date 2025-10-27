#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <QMainWindow>
#include <QGraphicsScene> // Graphics ke liye
#include <QTimer>         // Animation ke liye
#include <QVector>        // Array ke liye

class searching_window; // Agar aap isko use kar rahe hain

namespace Ui {
class linear_search;
}

class linear_search : public QMainWindow
{
    Q_OBJECT

public:
    // QWidget ki bajaye QMainWindow *parent use karna behtar hai
    explicit linear_search(QMainWindow *parent = nullptr);
    ~linear_search();

private slots:
    void on_btnResetlin_clicked();
    void on_btnRandomizelin_clicked();
    void on_btnPauselin_clicked();
    void on_btnsearchlin_clicked();
    void on_btnBacklin_clicked();
    void nextStep(); // Animation/Search step ke liye

private:
    Ui::linear_search *ui;
    searching_window* search_window = nullptr; // Agar use ho raha hai
    QGraphicsScene *scene;
    QVector<int> arr;
    QTimer *timer;
    int currentIndex;
    int searchValue;
    bool running;
    bool found;

    void drawArray(int highlightIndex = -1, bool isFound = false);
    void generateRandomArray();
    int stepDelayMs() const;
};

#endif // LINEAR_SEARCH_H
