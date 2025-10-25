#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorting_window.h"
#include "searching_window.h"
#include "graph_window.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btnSearching_clicked()
{
    hide(); // hides previous window
    search_window = new searching_window(this);
    search_window->show();
}


void MainWindow::on_btnSorting_clicked()
{
    hide();
    sort_window = new sorting_window(this);
    sort_window->show();
}


void MainWindow::on_btnGraph_clicked()
{
    hide();
    grph_window = new graph_window(this);
    grph_window->show();
}

