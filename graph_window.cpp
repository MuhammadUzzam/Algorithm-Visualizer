#include "graph_window.h"
#include "ui_graph_window.h"
#include "mainwindow.h"
#include "dfs_window.h"
#include "bfs_window.h"
#include <QRandomGenerator>

graph_window::graph_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::graph_window)
{
    ui->setupUi(this);

    // Example graph initialization (simple connected graph)
    adjList = {
        {1, 2},      // Node 0 connected to 1, 2
        {0, 3},      // Node 1 connected to 0, 3
        {0, 4},      // Node 2 connected to 0, 4
        {1},         // Node 3 connected to 1
        {2}          // Node 4 connected to 2
    };

    positions = {
        QPointF(300, 100),  // Node 0 (center top)
        QPointF(150, 250),  // Node 1 (left)
        QPointF(450, 250),  // Node 2 (right)
        QPointF(150, 400),  // Node 3 (bottom left)
        QPointF(450, 400)   // Node 4 (bottom right)
    };
}

graph_window::~graph_window()
{
    // Properly clean up child windows
    if(dfs) {
        dfs->close();
        delete dfs;
        dfs = nullptr;
    }

    if(main_window) {
        delete main_window;
        main_window = nullptr;
    }

    delete ui;
}

void graph_window::on_btnBack_clicked()
{
    // Create main window if it doesn't exist
    if(!main_window) {
        main_window = new MainWindow(nullptr);
    }

    main_window->show();
    this->close();
}

void graph_window::on_btnDFS_clicked()
{
    // Create DFS window if it doesn't exist
    if(!dfs) {
        dfs = new dfs_window(this);
    }

    // Pass graph data to DFS window
    dfs->setGraphData(adjList, positions);

    this->hide();
    dfs->show();
}

void graph_window::on_btnBFS_clicked()
{
    // Create BFS window if it doesn't exist
    if(!bfs) {
        bfs = new bfs_window(this);
    }

    // Pass graph data to BFS window
    bfs->setGraphData(adjList, positions);

    this->hide();
    bfs->show();
}

