// quick_sort.cpp
#include "quick_sort.h"
#include "ui_quick_sort.h"
#include "sorting_window.h"
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QMessageBox>

Quick_Sort::Quick_Sort(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Quick_Sort)
    , scene(new QGraphicsScene(this))
    , timer(new QTimer(this))
    , stepIndex(0)
    , running(false)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->lblOperation->setText("Click 'Randomize' to begin.");

    connect(timer, &QTimer::timeout, this, &Quick_Sort::nextStep);
    connect(ui->sliderSpeed, &QSlider::valueChanged, this, [=](int v){
        int actualInterval = ui->sliderSpeed->maximum() - v + ui->sliderSpeed->minimum();
        if (timer->isActive())
            timer->start(actualInterval);
    });
}

Quick_Sort::~Quick_Sort()
{
    delete ui;
}

void Quick_Sort::generateRandomArray()
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

void Quick_Sort::on_btnRandomize_clicked()
{
    timer->stop();
    running = false;
    generateRandomArray();
}

int Quick_Sort::partition(int left, int right)
{
    // Last element as pivot
    int pivot = tempArr[right];
    int i = left - 1;

    for (int j = left; j < right; ++j)
    {
        if (tempArr[j] < pivot)
        {
            i++;
            qSwap(tempArr[i], tempArr[j]);

            Step s;
            s.state = tempArr;
            s.pivot = right;
            s.left = i;
            s.right = j;
            steps.append(s);
        }
    }

    qSwap(tempArr[i + 1], tempArr[right]);

    Step s;
    s.state = tempArr;
    s.pivot = i + 1;
    s.left = left;
    s.right = right;
    steps.append(s);

    return i + 1;
}

void Quick_Sort::recordQuickSort(int left, int right)
{
    if (left < right)
    {
        int pi = partition(left, right);
        recordQuickSort(left, pi - 1);
        recordQuickSort(pi + 1, right);
    }
}

void Quick_Sort::on_btnStart_clicked()
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

        recordQuickSort(0, arr.size() - 1);

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

void Quick_Sort::nextStep()
{
    if (stepIndex < steps.size())
    {
        arr = steps[stepIndex].state;
        drawArray(steps[stepIndex].pivot, steps[stepIndex].left, steps[stepIndex].right);

        ui->lblOperation->setText(
            QString("Step %1/%2 - Pivot: %3, Comparing indices %4 and %5")
                .arg(stepIndex + 1)
                .arg(steps.size())
                .arg(arr[steps[stepIndex].pivot])
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

void Quick_Sort::drawArray(int pivot, int left, int right)
{
    scene->clear();
    int barWidth = 35;
    int spacing = 5;
    int x = 20;
    int baseY = 350;

    int maxVal = 1;
    for (int v : arr)
        maxVal = qMax(maxVal, v);

    for (int idx = 0; idx < arr.size(); ++idx)
    {
        int val = arr[idx];
        int h = (val * 250) / maxVal;

        QColor color = Qt::cyan;

        if (idx == pivot && pivot != -1)
            color = Qt::yellow;          // Pivot element
        else if (idx == left && left != -1)
            color = Qt::red;             // Left pointer
        else if (idx == right && right != -1)
            color = Qt::magenta;         // Right pointer

        scene->addRect(x, baseY - h, barWidth, h, QPen(Qt::black), QBrush(color));

        QGraphicsTextItem *text = scene->addText(QString::number(val));
        QFont font("Arial", 12, QFont::Bold);
        text->setFont(font);
        text->setDefaultTextColor(Qt::white);
        text->setPos(x + 5, baseY - h - 25);

        x += barWidth + spacing;
    }
}

int Quick_Sort::stepDelayMs() const
{
    return ui->sliderSpeed->maximum() - ui->sliderSpeed->value() + ui->sliderSpeed->minimum();
}

void Quick_Sort::on_btnPause_clicked()
{
    timer->stop();
    running = false;
    ui->lblOperation->setText("Paused.");
}

void Quick_Sort::on_btnReset_clicked()
{
    timer->stop();
    running = false;
    stepIndex = 0;
    steps.clear();
    generateRandomArray();
    ui->lblOperation->setText("Reset done.");
}

void Quick_Sort::on_btnBack_clicked()
{
    close();
    sort_window = new sorting_window(this);
    sort_window->show();
}
