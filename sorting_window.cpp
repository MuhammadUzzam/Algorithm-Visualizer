#include "sorting_window.h"
#include "ui_sorting_window.h"
#include "mainwindow.h"
#include "bubble_sort.h"
#include "merge_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "heap_sort.h"
#include "quick_sort.h"


sorting_window::sorting_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sorting_window)
{
    ui->setupUi(this);
}

sorting_window::~sorting_window()
{
    delete ui;
}

void sorting_window::on_btnBack_clicked()
{
    close();
    main_window = new MainWindow(this);
    main_window->show();
}


void sorting_window::on_btnBubbleSort_clicked()
{
    hide();
    bubb_sort = new bubble_sort(this);
    bubb_sort->show();
}


void sorting_window::on_btnselectionSort_clicked()
{
    hide();
    select_sort = new Selection_sort(this);
    select_sort->show();

}

void sorting_window::on_btnmergeSort_clicked()
{
    hide();
    merge_sort = new Merge_sort(this);
    merge_sort->show();
}


void sorting_window::on_btnheapSort_clicked()
{
    hide();
    heap_sort = new Heap_Sort(this);
    heap_sort->show();

}


void sorting_window::on_btnInsertionSort_clicked()
{
    hide();
    insertion_sort = new Insertion_sort(this);
    insertion_sort->show();

}


void sorting_window::on_btnsquickSort_3_clicked()
{
    hide();
    quick_sort = new Quick_Sort(this);
    quick_sort->show();
}


