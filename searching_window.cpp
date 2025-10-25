#include "searching_window.h"
#include "ui_searching_window.h"
#include "mainwindow.h"

searching_window::searching_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::searching_window)
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

