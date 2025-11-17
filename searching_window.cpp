#include "searching_window.h"
#include "ui_searching_window.h"
#include "mainwindow.h"
#include "linear_search.h"
#include "binary_search.h"  // <-- Nayi line: Binary Search ki header file shamil ki
#include <QDebug> // Debugging ke liye (agar zaroori ho)

searching_window::searching_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::searching_window)
    , linearSearchWindow(nullptr)
    , binarySearchWindow(nullptr)
{
    ui->setupUi(this);
}

searching_window::~searching_window()
{
    delete ui;
}

void searching_window::on_btnBack_clicked()
{
    close();
    main_window = new MainWindow(this);
    main_window->show();
}

void searching_window::on_btnLinearSearch_clicked()
{
    qDebug() << "Linear Search button clicked!";
    close();
    if (!linearSearchWindow) {
        linearSearchWindow = new linear_search(this);
    }
    linearSearchWindow->show();
}

void searching_window::on_btnBinarySearch_clicked()
{
    qDebug() << "Binary Search button clicked!";
    close();
    if (!binarySearchWindow) {
        binarySearchWindow = new binary_search(this);
    }
    binarySearchWindow->show();
}
