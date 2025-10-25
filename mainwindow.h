#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class searching_window;
class graph_window;
class sorting_window;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnSearching_clicked();

    void on_btnSorting_clicked();

    void on_btnGraph_clicked();

private:
    Ui::MainWindow *ui;
    searching_window* search_window;
    sorting_window* sort_window;
    graph_window* grph_window;
};
#endif // MAINWINDOW_H
