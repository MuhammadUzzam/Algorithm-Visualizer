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
    , binarySearchWindow(nullptr) // <-- Nayi line: Binary Search window ko initialize kiya
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
    main_window = new MainWindow(this); // Assuming MainWindow::MainWindow(QWidget* parent)
    main_window->show();
}

// Linear Search button slot (jaisa tha waisa hi hai)
void searching_window::on_btnLinearSearch_clicked()
{
    qDebug() << "Linear Search button clicked!";
    close();
    if (!linearSearchWindow) {
        linearSearchWindow = new linear_search(this); // Window ko QWidget parent de rahe hain
    }
    linearSearchWindow->show();
}

// Binary Search button slot (Naya function)
void searching_window::on_btnBinarySearch_clicked()
{
    qDebug() << "Binary Search button clicked!";
    close();
    if (!binarySearchWindow) {
        // Binary Search ki window kholne ka code
        binarySearchWindow = new binary_search(this); // Window ko QWidget parent de rahe hain
    }
    binarySearchWindow->show();
}
