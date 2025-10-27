#include "linear_search.h"
#include "ui_linear_search.h"
#include "searching_window.h" // Assuming this is your back button target
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QMessageBox>
#include <QDebug>
#include <QPainter> // For QPainter::Antialiasing

// Base class QMainWindow aur initialization list theek ki gayi hai
linear_search::linear_search(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::linear_search),
    scene(new QGraphicsScene(this)),
    timer(new QTimer(this)),
    currentIndex(0),
    searchValue(0),
    running(false),
    found(false)
{
    ui->setupUi(this);
    qDebug() << "Linear search constructor called";
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->lblOperation->setText("Click 'Randomize' to generate array.");

    // Timer connection
    connect(timer, &QTimer::timeout, this, &linear_search::nextStep);

    // Speed slider connection
    connect(ui->sliderSpeed, &QSlider::valueChanged, this, [=](int v){
        // Logic for converting slider value to interval time
        int actualInterval = ui->sliderSpeed->maximum() - v + ui->sliderSpeed->minimum();
        if (timer->isActive())
            timer->start(actualInterval);
    });
}

linear_search::~linear_search()
{
    delete ui;
}

void linear_search::generateRandomArray()
{
    arr.clear();
    for (int k = 0; k < 10; ++k)
        arr.append(QRandomGenerator::global()->bounded(10, 100));

    currentIndex = 0;
    found = false;
    drawArray();
    ui->lblOperation->setText("Random array generated! Enter a value to search.");
}

void linear_search::on_btnBacklin_clicked()
{
    close();
    // Assuming searching_window exists and needs the main window as parent
    if (!search_window) {
        search_window = new searching_window(this);
    }
    search_window->show();
}

void linear_search::on_btnResetlin_clicked()
{
    timer->stop();
    running = false;
    currentIndex = 0;
    found = false;
    drawArray();
    ui->lblOperation->setText("Reset done.");
}

int linear_search::stepDelayMs() const
{
    return ui->sliderSpeed->maximum() - ui->sliderSpeed->value() + ui->sliderSpeed->minimum();
}

void linear_search::nextStep()
{
    int n = arr.size();

    if (currentIndex >= n)
    {
        timer->stop();
        running = false;
        if (!found)
        {
            ui->lblOperation->setText(
                QString("Value %1 NOT FOUND in array!").arg(searchValue)
                );
        }
        drawArray();
        return;
    }

    drawArray(currentIndex, false);
    ui->lblOperation->setText(
        QString("Checking index %1: %2 == %3 ?")
            .arg(currentIndex)
            .arg(arr[currentIndex])
            .arg(searchValue)
        );

    if (arr[currentIndex] == searchValue)
    {
        found = true;
        timer->stop();
        running = false;
        drawArray(currentIndex, true);
        ui->lblOperation->setText(
            QString("FOUND! Value %1 at index %2")
                .arg(searchValue)
                .arg(currentIndex)
            );
        return;
    }

    currentIndex++;
}

void linear_search::drawArray(int highlightIndex, bool isFound)
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

        if (idx < currentIndex && !isFound)
            color = Qt::lightGray;
        else if (idx == highlightIndex && isFound)
            color = Qt::green;
        else if (idx == highlightIndex)
            color = Qt::yellow;

        scene->addRect(x, baseY - h, barWidth, h,
                       QPen(Qt::black), QBrush(color));

        QGraphicsTextItem *text = scene->addText(QString::number(val));
        text->setPos(x + 5, baseY - h - 25);

        QGraphicsTextItem *indexText = scene->addText(QString("[%1]").arg(idx));
        indexText->setPos(x + 5, baseY + 5);
        indexText->setDefaultTextColor(Qt::darkGray);

        x += barWidth + spacing;
    }
}

void linear_search::on_btnRandomizelin_clicked()
{
    generateRandomArray();
}

void linear_search::on_btnPauselin_clicked()
{
    timer->stop();
    running = false;
    ui->lblOperation->setText("Paused.");
}

void linear_search::on_btnsearchlin_clicked()
{
    if (arr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please generate array first!");
        return;
    }

    bool ok;
    // Assuming the line edit is named 'lineEdit'
    searchValue = ui->lineSearchEdit->text().toInt(&ok);

    if (!ok || ui->lineSearchEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a valid number to search!");
        return;
    }

    if (!running)
    {
        running = true;
        currentIndex = 0;
        found = false;
        timer->start(stepDelayMs());
        ui->lblOperation->setText(
            QString("Searching for %1...").arg(searchValue)
            );
    }
}
