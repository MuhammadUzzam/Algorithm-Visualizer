#ifndef SEARCHING_WINDOW_H
#define SEARCHING_WINDOW_H

#include <QMainWindow>

class MainWindow;

namespace Ui {
class searching_window;
}

class searching_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit searching_window(QWidget *parent = nullptr);
    ~searching_window();

private slots:
    void on_btnBack_clicked();

private:
    Ui::searching_window *ui;
    MainWindow* main_window;
};

#endif // SEARCHING_WINDOW_H
