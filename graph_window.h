#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPointF>

// Forward declarations to avoid circular dependencies
class MainWindow;
class dfs_window;
class bfs_window;

namespace Ui {
class graph_window;
}

class graph_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit graph_window(QWidget *parent = nullptr);
    ~graph_window();

    // Graph data
    QVector<QVector<int>> adjList;      // adjacency list
    QVector<QPointF> positions;         // node positions

private slots:
    void on_btnBack_clicked();
    void on_btnDFS_clicked();

    void on_btnBFS_clicked();

private:
    Ui::graph_window *ui;
    MainWindow* main_window = nullptr;
    dfs_window* dfs = nullptr;
    bfs_window* bfs = nullptr;
};

#endif // GRAPH_WINDOW_H
