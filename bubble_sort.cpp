#include "bubble_sort.h"
#include "ui_bubble_sort.h"
#include "mainwindow.h"
#include "sorting_window.h"

bubble_sort::bubble_sort(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bubble_sort)
{
    ui->setupUi(this);
}

bubble_sort::~bubble_sort()
{
    delete ui;
}

void bubble_sort::on_btnBack_clicked()
{
    close();
    sort_window = new sorting_window(this);
    sort_window->show();
}

