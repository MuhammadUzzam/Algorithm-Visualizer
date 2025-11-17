// insertion_sort.cpp
#include "insertion_sort.h"
#include "ui_insertion_sort.h"
#include "sorting_window.h"
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QMessageBox>

    Insertion_sort::Insertion_sort(QWidget *parent)
    : QMainWindow(parent)
, ui(new Ui::Insertion_sort)
, scene(new QGraphicsScene(this))
, timer(new QTimer(this))
, i(1), key(0), j(0)
, running(false)
, inserting(false)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->lblOperation->setText("Click 'Randomize' to begin.");

    connect(timer, &QTimer::timeout, this, &Insertion_sort::nextStep);
    connect(ui->sliderSpeed, &QSlider::valueChanged, this, [=](int v){
        int actualInterval = ui->sliderSpeed->maximum() - v + ui->sliderSpeed->minimum();
        if (timer->isActive())
            timer->start(actualInterval);
    });
}

Insertion_sort::~Insertion_sort()
{
    delete ui;
}

void Insertion_sort::generateRandomArray()
{
    arr.clear();
    for (int k = 0; k < 10; ++k)
        arr.append(QRandomGenerator::global()->bounded(10, 100));

    i = 1;
    j = 0;
    key = 0;
    inserting = false;
    drawArray();
    ui->lblOperation->setText("Random array generated!");
}

void Insertion_sort::on_btnBack_clicked()
{
    close();
    sort_window = new sorting_window(this);
    sort_window->show();
}

void Insertion_sort::on_btnReset_clicked()
{
    timer->stop();
    running = false;
    i = 1;
    j = 0;
    key = 0;
    inserting = false;
    drawArray();
    ui->lblOperation->setText("Reset done.");
}

int Insertion_sort::stepDelayMs() const
{
    return ui->sliderSpeed->maximum() - ui->sliderSpeed->value() + ui->sliderSpeed->minimum();
}

void Insertion_sort::nextStep()
{
    int n = arr.size();

    // Check if sorting is complete
    if (i >= n)
    {
        timer->stop();
        running = false;
        ui->lblOperation->setText("Sorting complete!");
        drawArray();
        return;
    }

    // If we're in insertion phase
    if (inserting)
    {
        // Perform the insertion (shift and insert)
        if (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            drawArray(i, j + 1, j);
            ui->lblOperation->setText(
                QString("Shifting %1 to right").arg(arr[j])
                );
            j--;
        }
        else
        {
            // Insert key at correct position
            arr[j + 1] = key;
            drawArray(i, j + 1);
            ui->lblOperation->setText(
                QString("Inserted %1 at position %2").arg(key).arg(j + 1)
                );

            // Move to next element
            i++;
            inserting = false;
        }
    }
    else
    {
        // Pick the key element
        key = arr[i];
        j = i - 1;
        inserting = true;
        drawArray(i, -1, i);
        ui->lblOperation->setText(
            QString("Position %1: Picked key element %2")
                .arg(i)
                .arg(key)
            );
    }
}

void Insertion_sort::drawArray(int currentIndex, int insertPos, int comparing)
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

        // Color coding for Insertion Sort
        if (idx < i && !inserting)
            color = Qt::green;           // Already sorted
        else if (idx == currentIndex)
            color = Qt::blue;            // Current key being picked
        else if (idx == insertPos)
            color = Qt::yellow;          // Position where inserting
        else if (idx == comparing)
            color = Qt::red;             // Currently comparing/shifting

        // All sorted
        if (i >= arr.size())
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

void Insertion_sort::on_btnRandomize_clicked()
{
    generateRandomArray();
}

void Insertion_sort::on_btnPause_clicked()
{
    timer->stop();
    running = false;
    ui->lblOperation->setText("Paused.");
}

void Insertion_sort::on_btnStart_clicked()
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
