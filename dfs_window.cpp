#include "dfs_window.h"
#include "ui_dfs_window.h"
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <QtMath>
#include <QDebug>
#include <QMouseEvent>

dfs_window::dfs_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dfs_window)
{
    ui->setupUi(this);

    // Scene setup
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Set scene rect for proper viewing
    scene->setSceneRect(0, 0, 600, 600);
    ui->graphicsView->setSceneRect(0, 0, 600, 600);

    // Install event filter for mouse interactions
    ui->graphicsView->viewport()->installEventFilter(this);
    ui->graphicsView->setMouseTracking(true);

    // Initialize timer
    animationTimer = new QTimer(this);
    animationTimer->setSingleShot(true);
    connect(animationTimer, &QTimer::timeout, this, &dfs_window::dfsStep);
}

dfs_window::~dfs_window()
{
    stopAnimation();
    if(scene) {
        scene->clear();
    }
    delete ui;
}

// Set graph from main window
void dfs_window::setGraphData(const QVector<QVector<int>> &adjList,
                              const QVector<QPointF> &positions)
{
    stopAnimation();
    adj = adjList;
    nodePositions = positions;
    visited = QVector<bool>(adj.size(), false);
    drawGraph();
}

// Draw nodes and edges
void dfs_window::drawGraph()
{
    scene->clear();
    nodeItems.clear();
    edgeItems.clear();

    if(nodePositions.isEmpty()) return;

    // Draw edges first (so they appear behind nodes)
    QSet<QPair<int,int>> drawnEdges; // To avoid duplicate edges

    for(int u = 0; u < adj.size(); ++u){
        for(int v : adj[u]){
            // Skip if edge already drawn (for undirected graphs)
            QPair<int,int> edge = qMakePair(qMin(u,v), qMax(u,v));
            if(drawnEdges.contains(edge)) continue;
            drawnEdges.insert(edge);

            if(u >= nodePositions.size() || v >= nodePositions.size()) continue;

            QLineF line(nodePositions[u], nodePositions[v]);
            auto edgeItem = scene->addLine(line, QPen(Qt::darkGray, 2));
            edgeItems.push_back(edgeItem);
        }
    }

    // Draw nodes
    for(int i = 0; i < nodePositions.size(); ++i){
        auto node = scene->addEllipse(
            nodePositions[i].x() - 15,
            nodePositions[i].y() - 15,
            30, 30,
            QPen(Qt::black, 2),
            QBrush(Qt::white)
            );
        nodeItems.push_back(node);

        auto text = scene->addText(QString::number(i));
        QFont font = text->font();
        font.setPointSize(12);
        font.setBold(true);
        text->setFont(font);

        // Center the text properly
        QRectF textRect = text->boundingRect();
        text->setPos(nodePositions[i].x() - textRect.width()/2,
                     nodePositions[i].y() - textRect.height()/2);
    }
}

// Color a node
void dfs_window::colorNode(int u, QColor color)
{
    if(u < 0 || u >= nodeItems.size()) return;
    nodeItems[u]->setBrush(QBrush(color));
}

// Stop animation
void dfs_window::stopAnimation()
{
    if(animationTimer && animationTimer->isActive()) {
        animationTimer->stop();
    }
    isAnimating = false;
}

// Start DFS button clicked
void dfs_window::on_btnRunDFS_clicked()
{
    stopAnimation();

    visited.fill(false);
    for(int i = 0; i < nodeItems.size(); ++i)
        colorNode(i, Qt::white);

    startDFS(0);
}

// Start DFS
void dfs_window::startDFS(int startNode)
{
    if(startNode < 0 || startNode >= adj.size()) return;

    dfsStack.clear();
    dfsStack.push_back(startNode);
    isAnimating = true;

    int interval = ui->speedSlider ? ui->speedSlider->value() : 500;
    animationTimer->start(interval);
}

// DFS step (true depth-first)
void dfs_window::dfsStep()
{
    if(!isAnimating) return;

    if(dfsStack.isEmpty()) {
        // Check disconnected components
        bool foundUnvisited = false;
        for(int i = 0; i < visited.size(); i++){
            if(!visited[i]){
                dfsStack.push_back(i);
                foundUnvisited = true;
                break;
            }
        }
        if(!foundUnvisited) {
            isAnimating = false;
            return;
        }
    }

    int u = dfsStack.takeLast();

    if(visited[u]){
        int interval = ui->speedSlider ? ui->speedSlider->value() : 500;
        animationTimer->start(interval);
        return;
    }

    visited[u] = true;
    colorNode(u, Qt::yellow); // Currently processing

    // Push neighbors in reverse order for correct DFS order
    for(int i = adj[u].size() - 1; i >= 0; --i){
        int v = adj[u][i];
        if(!visited[v]) {
            dfsStack.push_back(v);
        }
    }

    int interval = ui->speedSlider ? ui->speedSlider->value() : 500;

    // Create a single-shot timer for the second color change
    QTimer::singleShot(interval, this, [this, u](){
        if(!isAnimating) return;
        colorNode(u, Qt::green); // Finished processing

        int interval = ui->speedSlider ? ui->speedSlider->value() : 500;
        animationTimer->start(interval);
    });
}

// Back button
void dfs_window::on_btnBack_clicked()
{
    stopAnimation();
    QWidget *p = parentWidget();
    if(p) p->show();
    this->hide();
}

// Generate grid positions
void dfs_window::generateGridPositions(int nodes, QRectF bounds)
{
    nodePositions.clear();
    adj = QVector<QVector<int>>(nodes);
    visited = QVector<bool>(nodes, false);

    int cols = qCeil(qSqrt(nodes));
    int rows = qCeil((qreal)nodes / cols);

    qreal w = bounds.width() / (cols + 1);
    qreal h = bounds.height() / (rows + 1);

    int idx = 0;
    for(int r = 0; r < rows && idx < nodes; r++){
        for(int c = 0; c < cols && idx < nodes; c++){
            qreal x = (c + 1) * w;
            qreal y = (r + 1) * h;
            nodePositions.push_back(QPointF(x, y));
            idx++;
        }
    }
}

// Random graph generation
void dfs_window::on_btnRandomGraph_clicked()
{
    stopAnimation();

    int nodes = ui->spinNodeCount ? ui->spinNodeCount->value() : 6;
    if(nodes < 1) nodes = 1;
    if(nodes > 20) nodes = 20; // Limit for better visualization

    QRectF bounds = scene->sceneRect();
    if(bounds.isNull() || bounds.isEmpty()) {
        bounds = QRectF(0, 0, 600, 600);
    }

    generateGridPositions(nodes, bounds);

    // Generate random edges with 30% probability
    for(int u = 0; u < nodes; u++){
        for(int v = u + 1; v < nodes; v++){
            if(QRandomGenerator::global()->bounded(100) < 30){
                adj[u].push_back(v);
                adj[v].push_back(u); // Undirected graph
            }
        }
    }

    drawGraph();
}

// === MANUAL GRAPH CREATION FUNCTIONS ===

// Add node button clicked
void dfs_window::on_btnAddNode_clicked()
{
    currentMode = (currentMode == ADD_NODE) ? NONE : ADD_NODE;
    firstSelectedNode = -1;
    // updateUIForMode();
}

// Remove node button clicked
void dfs_window::on_btnRemoveNode_clicked()
{
    currentMode = (currentMode == REMOVE_NODE) ? NONE : REMOVE_NODE;
    firstSelectedNode = -1;
    // updateUIForMode();
}

// Add edge button clicked
void dfs_window::on_btnAddEdge_clicked()
{
    currentMode = (currentMode == ADD_EDGE) ? NONE : ADD_EDGE;
    firstSelectedNode = -1;
    // updateUIForMode();
}

// Clear graph button clicked
void dfs_window::on_btnClearGraph_clicked()
{
    stopAnimation();
    adj.clear();
    nodePositions.clear();
    visited.clear();
    currentMode = NONE;
    firstSelectedNode = -1;
    drawGraph();
    // updateUIForMode();
}

// Update UI based on current mode
void dfs_window::updateUIForMode()
{
    QString statusText;

    if(ui->btnAddNode) {
        ui->btnAddNode->setStyleSheet(
            currentMode == ADD_NODE ? "background-color: lightgreen;" : ""
            );
    }

    if(ui->btnRemoveNode) {
        ui->btnRemoveNode->setStyleSheet(
            currentMode == REMOVE_NODE ? "background-color: lightcoral;" : ""
            );
    }

    if(ui->btnAddEdge) {
        ui->btnAddEdge->setStyleSheet(
            currentMode == ADD_EDGE ? "background-color: lightblue;" : ""
            );
    }

    switch(currentMode) {
    case ADD_NODE:
        statusText = "Click anywhere to add a node";
        break;
    case REMOVE_NODE:
        statusText = "Click on a node to remove it";
        break;
    case ADD_EDGE:
        if(firstSelectedNode == -1)
            statusText = "Click on first node to create edge";
        else
            statusText = QString("Selected node %1. Click on second node").arg(firstSelectedNode);
        break;
    default:
        statusText = "Ready";
        break;
    }

    if(ui->statusbar) {
        ui->statusbar->showMessage(statusText);
    }
}

// Find node at given position
int dfs_window::findNodeAtPosition(QPointF scenePos)
{
    const qreal nodeRadius = 15.0;

    for(int i = 0; i < nodePositions.size(); i++) {
        qreal dx = nodePositions[i].x() - scenePos.x();
        qreal dy = nodePositions[i].y() - scenePos.y();
        qreal distSq = dx*dx + dy*dy;

        if(distSq <= nodeRadius * nodeRadius) {
            return i;
        }
    }

    return -1;
}

// Highlight node
void dfs_window::highlightNode(int nodeIdx, bool highlight)
{
    if(nodeIdx < 0 || nodeIdx >= nodeItems.size()) return;

    if(highlight) {
        nodeItems[nodeIdx]->setPen(QPen(Qt::blue, 3));
    } else {
        nodeItems[nodeIdx]->setPen(QPen(Qt::black, 2));
    }
}

// Add node at position
void dfs_window::addNode(QPointF position)
{
    int newIdx = nodePositions.size();
    nodePositions.push_back(position);
    adj.resize(newIdx + 1);
    visited.resize(newIdx + 1, false);

    drawGraph();
}

// Remove node
void dfs_window::removeNode(int nodeIdx)
{
    if(nodeIdx < 0 || nodeIdx >= nodePositions.size()) return;

    // Remove node from adjacency list
    nodePositions.remove(nodeIdx);
    adj.remove(nodeIdx);
    visited.remove(nodeIdx);

    // Update all adjacency lists (shift indices)
    for(int i = 0; i < adj.size(); i++) {
        // Remove references to deleted node
        adj[i].removeAll(nodeIdx);

        // Shift indices greater than nodeIdx
        for(int j = 0; j < adj[i].size(); j++) {
            if(adj[i][j] > nodeIdx) {
                adj[i][j]--;
            }
        }
    }

    drawGraph();
}

// Add edge between two nodes
void dfs_window::addEdge(int u, int v)
{
    if(u < 0 || u >= adj.size() || v < 0 || v >= adj.size()) return;
    if(u == v) return; // No self loops

    // Check if edge already exists
    if(adj[u].contains(v)) return;

    // Add edge (undirected)
    adj[u].push_back(v);
    adj[v].push_back(u);

    drawGraph();
}

// Remove edge between two nodes
void dfs_window::removeEdge(int u, int v)
{
    if(u < 0 || u >= adj.size() || v < 0 || v >= adj.size()) return;

    adj[u].removeAll(v);
    adj[v].removeAll(u);

    drawGraph();
}

// Event filter for mouse interactions
bool dfs_window::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->graphicsView->viewport()) {
        if(event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            QPointF scenePos = ui->graphicsView->mapToScene(mouseEvent->pos());

            int clickedNode = findNodeAtPosition(scenePos);

            switch(currentMode) {
            case ADD_NODE:
                if(clickedNode == -1) {
                    addNode(scenePos);
                }
                break;

            case REMOVE_NODE:
                if(clickedNode != -1) {
                    removeNode(clickedNode);
                }
                break;

            case ADD_EDGE:
                if(clickedNode != -1) {
                    if(firstSelectedNode == -1) {
                        firstSelectedNode = clickedNode;
                        highlightNode(firstSelectedNode, true);
                        // updateUIForMode();
                    } else {
                        addEdge(firstSelectedNode, clickedNode);
                        highlightNode(firstSelectedNode, false);
                        firstSelectedNode = -1;
                        // updateUIForMode();
                    }
                }
                break;

            default:
                break;
            }

            return true;
        }
        else if(event->type() == QEvent::MouseMove && currentMode != NONE) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            QPointF scenePos = ui->graphicsView->mapToScene(mouseEvent->pos());

            int hoveredNode = findNodeAtPosition(scenePos);

            // Update cursor based on mode
            if(currentMode == ADD_NODE && hoveredNode == -1) {
                ui->graphicsView->setCursor(Qt::CrossCursor);
            } else if((currentMode == REMOVE_NODE || currentMode == ADD_EDGE) && hoveredNode != -1) {
                ui->graphicsView->setCursor(Qt::PointingHandCursor);
            } else {
                ui->graphicsView->setCursor(Qt::ArrowCursor);
            }

            return true;
        }
    }

    return QMainWindow::eventFilter(obj, event);
}
