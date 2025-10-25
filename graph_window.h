#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include <QMainWindow>

class MainWindow;

namespace Ui {
class graph_window;
}

class graph_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit graph_window(QWidget *parent = nullptr);
    ~graph_window();

private slots:
    void on_btnBack_clicked();

private:
    Ui::graph_window *ui;
    MainWindow* main_window;
};

#endif // GRAPH_WINDOW_H
