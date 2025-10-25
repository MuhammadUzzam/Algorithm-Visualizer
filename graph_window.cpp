#include "graph_window.h"
#include "ui_graph_window.h"
#include "mainwindow.h"

graph_window::graph_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::graph_window)
{
    ui->setupUi(this);
}

graph_window::~graph_window()
{
    delete ui;
}

void graph_window::on_btnBack_clicked()
{
    close();
    main_window = new MainWindow(this);
    main_window->show();
}

