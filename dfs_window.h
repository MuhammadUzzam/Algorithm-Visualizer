#ifndef DFS_WINDOW_H
#define DFS_WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QVector>
#include <QTimer>

namespace Ui {
class dfs_window;
}

class dfs_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit dfs_window(QWidget *parent = nullptr);
    ~dfs_window();

    void setGraphData(const QVector<QVector<int>> &adjList,
                      const QVector<QPointF> &positions);

private slots:
    void on_btnBack_clicked();
    void on_btnRunDFS_clicked();
    void on_btnRandomGraph_clicked();
    void on_btnAddNode_clicked();
    void on_btnRemoveNode_clicked();
    void on_btnAddEdge_clicked();
    void on_btnClearGraph_clicked();
    void dfsStep();

private:
    Ui::dfs_window *ui;

    // Scene
    QGraphicsScene *scene = nullptr;
    QVector<QGraphicsEllipseItem*> nodeItems;
    QVector<QGraphicsLineItem*> edgeItems;

    // DFS stack and visited array
    QVector<int> dfsStack;
    QVector<bool> visited;

    // Graph data
    QVector<QVector<int>> adj;
    QVector<QPointF> nodePositions;

    // Timer for animation control
    QTimer *animationTimer = nullptr;
    bool isAnimating = false;

    // Manual graph creation mode
    enum EditMode { NONE, ADD_NODE, ADD_EDGE, REMOVE_NODE };
    EditMode currentMode = NONE;
    int firstSelectedNode = -1;  // For edge creation

    // Event handling for manual graph creation
    bool eventFilter(QObject *obj, QEvent *event) override;

    // Functions
    void drawGraph();
    void colorNode(int u, QColor color);
    void startDFS(int startNode = 0);
    void stopAnimation();
    int findNodeAtPosition(QPointF scenePos);
    void highlightNode(int nodeIdx, bool highlight);
    void addNode(QPointF position);
    void removeNode(int nodeIdx);
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    void updateUIForMode();

    // Grid layout generator
    void generateGridPositions(int nodes, QRectF bounds);
};

#endif // DFS_WINDOW_H
