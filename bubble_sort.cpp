#include "bubble_sort.h"
#include "ui_bubble_sort.h"
#include "mainwindow.h"
#include "sorting_window.h"
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QMessageBox>

bubble_sort::bubble_sort(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bubble_sort),
    scene(new QGraphicsScene(this)),
    timer(new QTimer(this)),
    i(0), j(0), running(false)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->lblOperation->setText("Click 'Randomize' to begin.");

    connect(timer, &QTimer::timeout, this, &bubble_sort::nextStep);
    connect(ui->sliderSpeed, &QSlider::valueChanged, this, [=](int v){
        int actualInterval = ui->sliderSpeed->maximum() - v + ui->sliderSpeed->minimum();
        if (timer->isActive())
            timer->start(actualInterval);
    });
}

bubble_sort::~bubble_sort()
{
    delete ui;
}

void bubble_sort::generateRandomArray()
{
    arr.clear();
    for (int k = 0; k < 10; ++k)
        arr.append(QRandomGenerator::global()->bounded(10, 100));
    i = 0;
    j = 0;
    drawArray();
    ui->lblOperation->setText("Random array generated!");
}

void bubble_sort::on_btnBack_clicked()
{
    close();
    sort_window = new sorting_window(this);
    sort_window->show();
}


void bubble_sort::on_btnReset_clicked()
{
    timer->stop();
    running = false;
    i = j = 0;
    drawArray();
    ui->lblOperation->setText("Reset done.");
}

int bubble_sort::stepDelayMs() const
{
    return ui->sliderSpeed->value();
}

void bubble_sort::nextStep()
{
    int n = arr.size();
    if (i >= n - 1)
    {
        timer->stop();
        running = false;
        ui->lblOperation->setText("Sorting complete!");
        drawArray();
        return;
    }

    drawArray(j, j + 1);
    ui->lblOperation->setText(
        QString("Comparing %1 and %2").arg(arr[j]).arg(arr[j + 1])
        );

    if (arr[j] > arr[j + 1])
    {
        std::swap(arr[j], arr[j + 1]);
        drawArray(j, j + 1);
    }

    j++;
    if (j >= n - i - 1)
    {
        j = 0;
        i++;
    }
}

void bubble_sort::drawArray(int highlight1, int highlight2)
{
    scene->clear();
    int barWidth = 40;
    int spacing = 10;
    int x = 20;
    int baseY = 300;

    int maxVal = 1;
    for (int v : arr) maxVal = qMax(maxVal, v);

    for (int idx = 0; idx < arr.size(); ++idx)
    {
        int val = arr[idx];
        int h = (val * 200) / maxVal;
        QColor color = Qt::cyan;
        if (idx == highlight1 || idx == highlight2) color = Qt::red;
        if (i >= arr.size() - 1) color = Qt::green;

        scene->addRect(x, baseY - h, barWidth, h, QPen(Qt::black), QBrush(color));
        QGraphicsTextItem *text = scene->addText(QString::number(val));
        QFont font("Arial", 12, QFont::Bold);
        text->setFont(font);
        text->setDefaultTextColor(Qt::white);
        text->setPos(x + 5, baseY - h - 25);

        x += barWidth + spacing;
    }
}


void bubble_sort::on_btnRandomize_clicked()
{
    generateRandomArray();
}


void bubble_sort::on_btnPause_clicked()
{
    timer->stop();
    running = false;
    ui->lblOperation->setText("Paused.");
}


void bubble_sort::on_btnStart_clicked()
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

