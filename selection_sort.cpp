#include "selection_sort.h"
#include "ui_selection_sort.h"
#include "sorting_window.h"
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QMessageBox>

Selection_sort::Selection_sort(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Selection_sort)
    , scene(new QGraphicsScene(this))
    , timer(new QTimer(this))
    , i(0), j(0), minIndex(0)
    , running(false)
    , swapping(false)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->lblOperation->setText("Click 'Randomize' to begin.");

    connect(timer, &QTimer::timeout, this, &Selection_sort::nextStep);
    connect(ui->sliderSpeed, &QSlider::valueChanged, this, [=](int v){
        int actualInterval = ui->sliderSpeed->maximum() - v + ui->sliderSpeed->minimum();
        if (timer->isActive())
            timer->start(actualInterval);
    });
}

Selection_sort::~Selection_sort()
{
    delete ui;
}

void Selection_sort::generateRandomArray()
{
    arr.clear();
    for (int k = 0; k < 10; ++k)
        arr.append(QRandomGenerator::global()->bounded(10, 100));

    i = 0;
    j = 1;
    minIndex = 0;
    swapping = false;
    drawArray();
    ui->lblOperation->setText("Random array generated!");
}

void Selection_sort::on_btnBack_clicked()
{
    close();
    sort_window = new sorting_window(this);
    sort_window->show();
}

void Selection_sort::on_btnReset_clicked()
{
    timer->stop();
    running = false;
    i = 0;
    j = 1;
    minIndex = 0;
    swapping = false;
    drawArray();
    ui->lblOperation->setText("Reset done.");
}

int Selection_sort::stepDelayMs() const
{
    return ui->sliderSpeed->maximum() - ui->sliderSpeed->value() + ui->sliderSpeed->minimum();
}

void Selection_sort::nextStep()
{
    int n = arr.size();

    // Check if sorting is complete
    if (i >= n - 1)
    {
        timer->stop();
        running = false;
        ui->lblOperation->setText("Sorting complete!");
        drawArray();
        return;
    }

    // If we're in swapping phase
    if (swapping)
    {
        // Perform the swap
        std::swap(arr[i], arr[minIndex]);
        drawArray(i, minIndex);
        ui->lblOperation->setText(
            QString("Swapped %1 with %2").arg(arr[minIndex]).arg(arr[i])
            );

        // Move to next position
        i++;
        j = i + 1;
        minIndex = i;
        swapping = false;
        return;
    }

    // Finding minimum element
    if (j < n)
    {
        drawArray(i, minIndex, j);
        ui->lblOperation->setText(
            QString("Position %1: Comparing %2 with current min %3")
                .arg(i)
                .arg(arr[j])
                .arg(arr[minIndex])
            );

        // Update minimum if found smaller element
        if (arr[j] < arr[minIndex])
        {
            minIndex = j;
            ui->lblOperation->setText(
                QString("New minimum found: %1 at index %2")
                    .arg(arr[minIndex])
                    .arg(minIndex)
                );
        }

        j++;
    }
    else
    {
        // Finished scanning, prepare to swap
        if (minIndex != i)
        {
            swapping = true;
            ui->lblOperation->setText(
                QString("Minimum is %1, preparing to swap with position %2")
                    .arg(arr[minIndex])
                    .arg(i)
                );
        }
        else
        {
            // Already in correct position
            ui->lblOperation->setText(
                QString("Element %1 already in correct position")
                    .arg(arr[i])
                );
            i++;
            j = i + 1;
            minIndex = i;
        }
    }
}

void Selection_sort::drawArray(int currentIndex, int minIdx, int comparing)
{
    scene->clear();
    int barWidth = 40;
    int spacing = 10;
    int x = 20;
    int baseY = 300;
    int maxVal = 1;

    for (int v : arr)
        maxVal = qMax(maxVal, v);

    for (int idx = 0; idx < arr.size(); ++idx)
    {
        int val = arr[idx];
        int h = (val * 200) / maxVal;

        QColor color = Qt::cyan;

        // Color coding for Selection Sort
        if (idx < i && i < arr.size() - 1)
            color = Qt::green;          // Already sorted
        else if (idx == currentIndex)
            color = Qt::blue;            // Current position being filled
        else if (idx == minIdx)
            color = Qt::yellow;          // Current minimum
        else if (idx == comparing)
            color = Qt::red;             // Currently comparing

        // All sorted
        if (i >= arr.size() - 1)
            color = Qt::green;

        scene->addRect(x, baseY - h, barWidth, h,
                       QPen(Qt::black), QBrush(color));

        // Display value on top
        QGraphicsTextItem *text = scene->addText(QString::number(val));
        QFont font("Arial", 12, QFont::Bold);
        text->setFont(font);
        text->setDefaultTextColor(Qt::white);
        text->setPos(x + 5, baseY - h - 25);

        x += barWidth + spacing;
    }
}

void Selection_sort::on_btnRandomize_clicked()
{
    generateRandomArray();
}

void Selection_sort::on_btnPause_clicked()
{
    timer->stop();
    running = false;
    ui->lblOperation->setText("Paused.");
}

void Selection_sort::on_btnStart_clicked()
{
    if (arr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please randomize first!");
        return;
    }

    if (!running)
    {
        running = true;
        timer->start(stepDelayMs());
        ui->lblOperation->setText("Sorting started...");
    }
}
