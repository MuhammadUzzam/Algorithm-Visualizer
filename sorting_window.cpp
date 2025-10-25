#include "sorting_window.h"
#include "ui_sorting_window.h"
#include "mainwindow.h"
#include "bubble_sort.h"

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

