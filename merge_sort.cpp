// merge_sort.cpp
#include "merge_sort.h"
#include "ui_merge_sort.h"
#include "sorting_window.h"
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QMessageBox>

Merge_sort::Merge_sort(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Merge_sort)
    , scene(new QGraphicsScene(this))
    , timer(new QTimer(this))
    , stepIndex(0)
    , running(false)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->lblOperation->setText("Click 'Randomize' to begin.");

    connect(timer, &QTimer::timeout, this, &Merge_sort::nextStep);
    connect(ui->sliderSpeed, &QSlider::valueChanged, this, [=](int v){
        int actualInterval = ui->sliderSpeed->maximum() - v + ui->sliderSpeed->minimum();
        if (timer->isActive())
            timer->start(actualInterval);
    });
}

Merge_sort::~Merge_sort()
{
    delete ui;
}

void Merge_sort::generateRandomArray()
{
    arr.clear();
    steps.clear();
    stepIndex = 0;

    for (int k = 0; k < 10; ++k)
        arr.append(QRandomGenerator::global()->bounded(10, 100));

    tempArr = arr;
    drawArray();
    ui->lblOperation->setText("Random array generated!");
}

void Merge_sort::on_btnRandomize_clicked()
{
    timer->stop();
    running = false;
    generateRandomArray();
}

void Merge_sort::recordMergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        recordMergeSort(left, mid);
        recordMergeSort(mid + 1, right);

        QList<int> leftArr(tempArr.begin() + left, tempArr.begin() + mid + 1);
        QList<int> rightArr(tempArr.begin() + mid + 1, tempArr.begin() + right + 1);

        int i = 0, j = 0, k = left;
        while (i < leftArr.size() && j < rightArr.size())
        {
            if (leftArr[i] <= rightArr[j])
                tempArr[k++] = leftArr[i++];
            else
                tempArr[k++] = rightArr[j++];
        }
        while (i < leftArr.size())
            tempArr[k++] = leftArr[i++];
        while (j < rightArr.size())
            tempArr[k++] = rightArr[j++];

        Step s;
        s.state = tempArr;
        s.left = left;
        s.right = right;
        steps.append(s);
    }
}

void Merge_sort::on_btnStart_clicked()
{
    if (arr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please randomize first!");
        return;
    }

    if (!running) {
        running = true;
        stepIndex = 0;
        steps.clear();
        tempArr = arr;

        recordMergeSort(0, arr.size() - 1);

        if (steps.isEmpty()) {
            arr = tempArr;
            drawArray();
            ui->lblOperation->setText("Sorting complete!");
            running = false;
        } else {
            timer->start(stepDelayMs());
        }
    }
}

void Merge_sort::nextStep()
{
    if (stepIndex < steps.size())
    {
        arr = steps[stepIndex].state;
        drawArray(steps[stepIndex].left, steps[stepIndex].right);

        ui->lblOperation->setText(
            QString("Step %1/%2 - Merging indices %3 to %4")
                .arg(stepIndex + 1)
                .arg(steps.size())
                .arg(steps[stepIndex].left)
                .arg(steps[stepIndex].right)
            );

        stepIndex++;
    }
    else
    {
        timer->stop();
        running = false;
        drawArray();
        ui->lblOperation->setText("Sorting complete!");
    }
}

void Merge_sort::drawArray(int highlight1, int highlight2)
{
    scene->clear();
    int barWidth = 35;
    int spacing = 5;
    int x = 20;
    int baseY = 350;

    int maxVal = 1;
    for (int v : arr) maxVal = qMax(maxVal, v);

    for (int idx = 0; idx < arr.size(); ++idx)
    {
        int val = arr[idx];
        int h = (val * 250) / maxVal;

        QColor color = Qt::cyan;
        if (idx >= highlight1 && idx <= highlight2 && highlight1 != -1)
            color = Qt::red;

        scene->addRect(x, baseY - h, barWidth, h, QPen(Qt::black), QBrush(color));

        QGraphicsTextItem *text = scene->addText(QString::number(val));
        text->setPos(x + 5, baseY - h - 25);

        x += barWidth + spacing;
    }
}

int Merge_sort::stepDelayMs() const
{
    return ui->sliderSpeed->value();
}

void Merge_sort::on_btnPause_clicked()
{
    timer->stop();
    running = false;
    ui->lblOperation->setText("Paused.");
}

void Merge_sort::on_btnReset_clicked()
{
    timer->stop();
    running = false;
    stepIndex = 0;
    steps.clear();
    generateRandomArray();
    ui->lblOperation->setText("Reset done.");
}

void Merge_sort::on_btnBack_clicked()
{
    timer->stop();
    close();
}

