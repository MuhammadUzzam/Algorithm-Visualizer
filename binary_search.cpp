#include "binary_search.h"
#include "ui_binary_search.h"
#include "searching_window.h" // Assuming this is your back button target
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QMessageBox>
#include <QDebug>
#include <QPainter>

// Base class QMainWindow aur initialization list theek ki gayi hai
binary_search::binary_search(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::binary_search),
    scene(new QGraphicsScene(this)),
    timer(new QTimer(this)),
    lowIndex(0),
    highIndex(0),
    midIndex(-1),
    searchValue(0),
    running(false),
    found(false)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->lblOperation->setText("Binary Search. Click 'Randomize' to start.");

    // Timer connection
    connect(timer, &QTimer::timeout, this, &binary_search::nextStep);

    // Speed slider connection (assuming sliderSpeed is the object name)
    connect(ui->sliderSpeed, &QSlider::valueChanged, this, [=](int v){
        // Logic for converting slider value to interval time
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

    // Binary Search ke liye array ka sort hona ZAROORI hai
    std::sort(arr.begin(), arr.end());

    lowIndex = 0;
    highIndex = arr.size() - 1;
    midIndex = -1;
    found = false;
    drawArray();
    ui->lblOperation->setText("Sorted array generated! Enter a value to search.");
}

void binary_search::on_btnBacklin_clicked()
{
    close();
    // Assuming searching_window exists
    if (!search_window) {
        search_window = new searching_window(this);
    }
    search_window->show();
}

void binary_search::on_btnResetbin_clicked()
{
    timer->stop();
    running = false;
    lowIndex = 0;
    highIndex = arr.size() - 1;
    midIndex = -1;
    found = false;
    drawArray();
    ui->lblOperation->setText("Reset done. Array is sorted.");
}

int binary_search::stepDelayMs() const
{
    // Adjust this logic based on how you want the slider to work
    return ui->sliderSpeed->maximum() - ui->sliderSpeed->value() + ui->sliderSpeed->minimum();
}

void binary_search::nextStep()
{
    // Base Case: Element not found (low > high)
    if (lowIndex > highIndex)
    {
        timer->stop();
        running = false;
        ui->lblOperation->setText(
            QString("Value %1 NOT FOUND in array!").arg(searchValue)
            );
        drawArray(); // Final state (no highlights)
        return;
    }

    // Binary Search Logic
    midIndex = lowIndex + (highIndex - lowIndex) / 2;
    drawArray(lowIndex, highIndex, midIndex);

    ui->lblOperation->setText(
        QString("Checking Mid Index %1: Value %2 == %3 ?")
            .arg(midIndex)
            .arg(arr[midIndex])
            .arg(searchValue)
        );

    // Case 1: Found
    if (arr[midIndex] == searchValue)
    {
        found = true;
        timer->stop();
        running = false;
        drawArray(-1, -1, midIndex, true); // Found highlight
        ui->lblOperation->setText(
            QString("FOUND! Value %1 at index %2").arg(searchValue).arg(midIndex)
            );
        return;
    }
    // Case 2: Value is in the left half
    else if (arr[midIndex] > searchValue)
    {
        highIndex = midIndex - 1;
    }
    // Case 3: Value is in the right half
    else // arr[midIndex] < searchValue
    {
        lowIndex = midIndex + 1;
    }

    // Draw next state without stopping
    // nextStep will be called again by the timer
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

        // Color coding logic (No change here, this is already fine)
        if (isFound && idx == mid)
            color = Qt::green; // Found!
        else if (idx == mid)
            color = Qt::yellow; // Currently checking (Mid)
        else if (idx >= low && idx <= high)
            color = Qt::blue; // Active Search Range
        else
            color = Qt::lightGray; // Out of Range/Ignored

        scene->addRect(x, baseY - h, barWidth, h,
                       QPen(Qt::black), QBrush(color));

        // Display value on top (No change)
        QGraphicsTextItem *text = scene->addText(QString::number(val));
        text->setPos(x + 5, baseY - h - 25);

        // Display index below (No change)
        QGraphicsTextItem *indexText = scene->addText(QString("[%1]").arg(idx));
        indexText->setPos(x + 5, baseY + 5);
        indexText->setDefaultTextColor(Qt::darkGray);


        QString pointerLabel;
        QColor pointerColor;
        int pointerOffset = 20; // Index text se thoda neeche

        // Mid pointer
        if (idx == mid && mid != -1) {
            pointerLabel += "M";
            pointerColor = Qt::red;
        }

        // Low pointer (M se neeche dikhana hai agar dono same hain)
        if (idx == low && low != -1) {
            if (!pointerLabel.isEmpty()) pointerLabel += "/";
            pointerLabel += "L";
            pointerColor = Qt::darkGreen;
        }

        // High pointer (L aur M se neeche dikhana hai agar same hain)
        if (idx == high && high != -1) {
            if (!pointerLabel.isEmpty()) pointerLabel += "/";
            pointerLabel += "H";
            pointerColor = Qt::darkMagenta;
        }

        if (!pointerLabel.isEmpty()) {
            QGraphicsTextItem *pointerText = scene->addText(pointerLabel);
            pointerText->setPos(x + 5, baseY + 5 + pointerOffset); // Index se 20px neeche
            pointerText->setDefaultTextColor(pointerColor);
            pointerText->setFont(QFont("Arial", 10, QFont::Bold));
        }

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
        QMessageBox::warning(this, "Error", "Please generate array first!");
        return;
    }

    bool ok;
    // Assuming the line edit is named 'lineSearchEdit' (like your last fix)
    int inputVal = ui->lineSearchEdit->text().toInt(&ok);

    if (!ok || ui->lineSearchEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a valid number to search!");
        return;
    }

    // Agar search shuru nahi hua hai ya naya search shuru karna hai
    if (!running || inputVal != searchValue)
    {
        searchValue = inputVal;
        running = true;
        found = false;

        // Indices ko reset karo naye search ke liye
        lowIndex = 0;
        highIndex = arr.size() - 1;
        midIndex = -1;

        timer->start(stepDelayMs());
        ui->lblOperation->setText(
            QString("Searching for %1... (Low: %2, High: %3)").arg(searchValue).arg(lowIndex).arg(highIndex)
            );
    }
}
