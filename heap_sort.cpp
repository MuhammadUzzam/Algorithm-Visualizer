// heap_sort.cpp
#include "heap_sort.h"
#include "ui_heap_sort.h"
#include "sorting_window.h"
#include <QRandomGenerator>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

Heap_Sort::Heap_Sort(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Heap_Sort), scene(new QGraphicsScene(this)),
    timer(new QTimer(this)), stepIndex(0), animationStep(0), running(false), isMinHeap(false)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->lineSearchEdit->setPlaceholderText("Enter value...");
    ui->lblOperation->setText("Enter values and click Insert");
    connect(timer, &QTimer::timeout, this, &Heap_Sort::nextAnimationStep);
    timer->setInterval(500);
}

Heap_Sort::~Heap_Sort() { delete ui; }

void Heap_Sort::generateRandomArray(int size)
{
    arr.clear();
    swapSteps.clear();
    animationStep = 0;
    for (int i = 0; i < size; i++)
        arr.append(QRandomGenerator::global()->bounded(10, 100));
    drawHeapTree();
    ui->lblOperation->setText("Random array generated!");
}

void Heap_Sort::on_btnRandomize_clicked()
{
    timer->stop();
    running = false;
    animationStep = 0;
    generateRandomArray(7);
}

void Heap_Sort::recordSwap(int i, int j) { swapSteps.append({i, j}); }

void Heap_Sort::heapify(int n, int i, bool recordSteps)
{
    int extreme = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (isMinHeap) {
        if (left < n && arr[left] < arr[extreme]) extreme = left;
        if (right < n && arr[right] < arr[extreme]) extreme = right;
    } else {
        if (left < n && arr[left] > arr[extreme]) extreme = left;
        if (right < n && arr[right] > arr[extreme]) extreme = right;
    }

    if (extreme != i) {
        if (recordSteps) recordSwap(i, extreme);
        qSwap(arr[i], arr[extreme]);
        heapify(n, extreme, recordSteps);
    }
}

void Heap_Sort::heapSort(int n)
{
    swapSteps.clear();
    animationStep = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i, true);
    for (int i = n - 1; i > 0; i--) {
        recordSwap(0, i);
        qSwap(arr[0], arr[i]);
        heapify(i, 0, true);
    }
}

void Heap_Sort::nextAnimationStep()
{
    if (animationStep < swapSteps.size()) {
        drawHeapTree(swapSteps[animationStep].first, swapSteps[animationStep].second);
        ui->lblOperation->setText(
            QString("Step %1/%2 - Swapping %3 and %4")
                .arg(animationStep + 1).arg(swapSteps.size())
                .arg(swapSteps[animationStep].first).arg(swapSteps[animationStep].second));
        animationStep++;
    } else {
        timer->stop();
        running = false;
        drawHeapTree();
        ui->lblOperation->setText("Sorting complete!");
    }
}

void Heap_Sort::on_btnStart_clicked()
{
    if (arr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please add values first!");
        return;
    }
    if (!running) {
        running = true;
        animationStep = 0;
        swapSteps.clear();
        heapSort(arr.size());
        if (!swapSteps.isEmpty()) timer->start();
    }
}

void Heap_Sort::drawHeapTree(int highlightIdx1, int highlightIdx2)
{
    scene->clear();
    if (!arr.isEmpty()) drawNode(0, 500, 30, 150, highlightIdx1, highlightIdx2);
}

void Heap_Sort::drawNode(int idx, int x, int y, int offset, int highlightIdx1, int highlightIdx2)
{
    if (idx >= arr.size()) return;
    int left = 2 * idx + 1, right = 2 * idx + 2;

    if (left < arr.size()) {
        scene->addLine(x, y + 20, x - offset, y + 80, QPen(Qt::black, 2));
        drawNode(left, x - offset, y + 80, offset / 2, highlightIdx1, highlightIdx2);
    }
    if (right < arr.size()) {
        scene->addLine(x, y + 20, x + offset, y + 80, QPen(Qt::black, 2));
        drawNode(right, x + offset, y + 80, offset / 2, highlightIdx1, highlightIdx2);
    }

    QColor nodeColor = (idx == highlightIdx1 || idx == highlightIdx2) ? Qt::red : Qt::cyan;
    scene->addEllipse(x - 20, y, 40, 40, QPen(Qt::black, 2), QBrush(nodeColor));
    QGraphicsTextItem *text = scene->addText(QString::number(arr[idx]));
    text->setPos(x - 10, y + 8);
    text->setDefaultTextColor(Qt::black);
}

void Heap_Sort::on_btnReset_clicked()
{
    timer->stop();
    running = false;
    animationStep = 0;
    arr.clear();
    swapSteps.clear();
    scene->clear();
    ui->lineSearchEdit->clear();
    ui->lblOperation->setText("Reset done. Enter values and click Insert");
}

void Heap_Sort::on_btninsert_clicked()
{
    QString text = ui->lineSearchEdit->text();
    if (text.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a value!");
        return;
    }
    bool ok;
    int value = text.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Error", "Please enter a valid number!");
        return;
    }
    arr.append(value);
    ui->lineSearchEdit->clear();
    drawHeapTree();
    ui->lblOperation->setText(QString("Value %1 inserted. Total: %2").arg(value).arg(arr.size()));
}

void Heap_Sort::on_lineSearchEdit_cursorPositionChanged(int, int) {}
void Heap_Sort::nextStep() {}
void Heap_Sort::on_btnBack_clicked()
{
    close();
    sort_window = new sorting_window(this);
    sort_window->show();
}
void Heap_Sort::on_btnminheap_clicked()
{
    timer->stop();
    running = false;
    animationStep = 0;
    swapSteps.clear();
    arr.clear();
    scene->clear();
    ui->lineSearchEdit->clear();
    isMinHeap = false;  // Min heap mode = Max heap logic (reversed)
    ui->lblOperation->setText("Min Heap mode selected. Add values to continue.");
}

void Heap_Sort::on_btnmaxheap_clicked()
{
    timer->stop();
    running = false;
    animationStep = 0;
    swapSteps.clear();
    arr.clear();
    scene->clear();
    ui->lineSearchEdit->clear();
    isMinHeap = true;  // Max heap mode = Min heap logic (reversed)
    ui->lblOperation->setText("Max Heap mode selected. Add values to continue.");
}
