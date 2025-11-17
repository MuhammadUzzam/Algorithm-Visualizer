// binary_search.cpp
#include "binary_search.h"
#include "ui_binary_search.h"
#include "searching_window.h"
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QMessageBox>
#include <QPainter>

binary_search::binary_search(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::binary_search),
    search_window(nullptr),
    scene(new QGraphicsScene(this)),
    timer(new QTimer(this)),
    low(0),
    high(0),
    mid(-1),
    searchValue(0),
    running(false),
    found(false)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->lblOperation->setText("Click 'Randomize' to start.");

    connect(timer, &QTimer::timeout, this, &binary_search::nextStep);

    // Slider connection - Linear search pattern
    connect(ui->sliderSpeed, &QSlider::valueChanged, this, [=](int v){
        int actualInterval = ui->sliderSpeed->maximum() - v + ui->sliderSpeed->minimum();
        if (timer->isActive())
            timer->start(actualInterval);
    });
}

binary_search::~binary_search()
{
    delete ui;
}

void binary_search::generateRandomAndSortArray()
{
    arr.clear();
    for (int k = 0; k < 10; ++k)
        arr.append(QRandomGenerator::global()->bounded(10, 100));

    std::sort(arr.begin(), arr.end());

    low = 0;
    high = arr.size() - 1;
    mid = -1;
    found = false;
    drawArray();
    ui->lblOperation->setText("Sorted array generated! Enter a value to search.");
}

void binary_search::on_btnBacklin_clicked()
{
    close();
    if (!search_window) {
        search_window = new searching_window(this);
    }
    search_window->show();
}

void binary_search::on_btnResetbin_clicked()
{
    timer->stop();
    running = false;
    low = 0;
    high = arr.size() - 1;
    mid = -1;
    found = false;
    drawArray();
    ui->lblOperation->setText("Reset done.");
}

int binary_search::stepDelayMs() const
{
    return ui->sliderSpeed->maximum() - ui->sliderSpeed->value() + ui->sliderSpeed->minimum();
}

void binary_search::nextStep()
{
    // Element not found
    if (low > high)
    {
        timer->stop();
        running = false;
        ui->lblOperation->setText(QString("Value %1 NOT FOUND!").arg(searchValue));
        drawArray();
        return;
    }

    // Calculate mid
    mid = low + (high - low) / 2;
    drawArray(low, high, mid);

    ui->lblOperation->setText(
        QString("Checking index %1: %2 == %3 ?").arg(mid).arg(arr[mid]).arg(searchValue)
        );

    if (arr[mid] == searchValue)
    {
        found = true;
        timer->stop();
        running = false;
        drawArray(-1, -1, mid, true);
        ui->lblOperation->setText(QString("FOUND! Value %1 at index %2").arg(searchValue).arg(mid));
        return;
    }
    else if (arr[mid] > searchValue)
        high = mid - 1;
    else
        low = mid + 1;
}

void binary_search::drawArray(int low, int high, int mid, bool isFound)
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

        if (isFound && idx == mid)
            color = Qt::green;
        else if (idx == mid)
            color = Qt::yellow;
        else if (idx >= low && idx <= high)
            color = Qt::blue;
        else
            color = Qt::lightGray;

        scene->addRect(x, baseY - h, barWidth, h, QPen(Qt::black), QBrush(color));

        // White bold text
        QGraphicsTextItem *text = scene->addText(QString::number(val));
        QFont font("Arial", 12, QFont::Bold);
        text->setFont(font);
        text->setDefaultTextColor(Qt::white);
        text->setPos(x + 5, baseY - h - 25);

        // Index
        QGraphicsTextItem *indexText = scene->addText(QString("[%1]").arg(idx));
        indexText->setPos(x + 5, baseY + 5);
        indexText->setDefaultTextColor(Qt::darkGray);

        x += barWidth + spacing;
    }
}

void binary_search::on_btnRandomizebin_clicked()
{
    timer->stop();
    running = false;
    generateRandomAndSortArray();
}

void binary_search::on_btnPausebin_clicked()
{
    timer->stop();
    running = false;
    ui->lblOperation->setText("Paused.");
}

void binary_search::on_btnsearchbin_clicked()
{
    if (arr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please randomize first!");
        return;
    }

    bool ok;
    searchValue = ui->lineSearchEdit->text().toInt(&ok);

    if (!ok || ui->lineSearchEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a valid number!");
        return;
    }

    if (!running)
    {
        running = true;
        found = false;
        low = 0;
        high = arr.size() - 1;
        mid = -1;

        timer->start(stepDelayMs());
        ui->lblOperation->setText(QString("Searching for %1...").arg(searchValue));
    }
}
