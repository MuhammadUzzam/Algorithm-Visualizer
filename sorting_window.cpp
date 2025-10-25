#include "sorting_window.h"
#include "ui_sorting_window.h"
#include "mainwindow.h"

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

