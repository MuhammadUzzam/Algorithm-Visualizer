/********************************************************************************
** Form generated from reading UI file 'graph_window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_WINDOW_H
#define UI_GRAPH_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graph_window
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnDFS;
    QPushButton *btnBFS;
    QPushButton *btnBack;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *graph_window)
    {
        if (graph_window->objectName().isEmpty())
            graph_window->setObjectName("graph_window");
        graph_window->resize(800, 600);
        graph_window->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #1e1b4b,      /* Indigo */\n"
"        stop:0.5 #581c87,    /* Purple */\n"
"        stop:1 #831843       /* Pink */\n"
"    );\n"
"}"));
        centralwidget = new QWidget(graph_window);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        btnDFS = new QPushButton(centralwidget);
        btnDFS->setObjectName("btnDFS");
        btnDFS->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Segoe UI Semibold\", \"Times New Roman\", Arial, sans-serif;\n"
"    font-size: 18px;\n"
"    color: white;\n"
"    background: qlineargradient(\n"
"        spread:pad,\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #0077b6,\n"
"        stop:1 #48cae4\n"
"    );\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    letter-spacing: 1px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        spread:pad,\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #48cae4,\n"
"        stop:1 #90e0ef\n"
"    );\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #023e8a;\n"
"}\n"
"\n"
""));

        verticalLayout->addWidget(btnDFS);

        btnBFS = new QPushButton(centralwidget);
        btnBFS->setObjectName("btnBFS");
        btnBFS->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Segoe UI Semibold\", \"Times New Roman\", Arial, sans-serif;\n"
"    font-size: 18px;\n"
"    color: white;\n"
"    background: qlineargradient(\n"
"        spread:pad,\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #0077b6,\n"
"        stop:1 #48cae4\n"
"    );\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    letter-spacing: 1px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        spread:pad,\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #48cae4,\n"
"        stop:1 #90e0ef\n"
"    );\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #023e8a;\n"
"}\n"
"\n"
""));

        verticalLayout->addWidget(btnBFS);

        btnBack = new QPushButton(centralwidget);
        btnBack->setObjectName("btnBack");
        btnBack->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"        background: qlineargradient(stop:0 #ffffff, stop:1 #f3f4f6);\n"
"        color: #1a0033;\n"
"        font-size: 16px;\n"
"        font-weight: 700;\n"
"        border: 2px solid #e5e7eb;\n"
"        border-radius: 20px;\n"
"        padding: 10px 20px;\n"
"        transition: all 0.3s ease;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background: qlineargradient(stop:0 #e5e7eb, stop:1 #d1d5db);\n"
"        border: 2px solid #9ca3af;\n"
"        color: #0f172a;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background: qlineargradient(stop:0 #9ca3af, stop:1 #6b7280);\n"
"        border: 2px solid #6b7280;\n"
"        color: #0f172a;\n"
"        padding: 11px 20px 9px 20px;\n"
"    }"));

        verticalLayout->addWidget(btnBack);

        graph_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(graph_window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        graph_window->setMenuBar(menubar);
        statusbar = new QStatusBar(graph_window);
        statusbar->setObjectName("statusbar");
        graph_window->setStatusBar(statusbar);

        retranslateUi(graph_window);

        QMetaObject::connectSlotsByName(graph_window);
    } // setupUi

    void retranslateUi(QMainWindow *graph_window)
    {
        graph_window->setWindowTitle(QCoreApplication::translate("graph_window", "MainWindow", nullptr));
        btnDFS->setText(QCoreApplication::translate("graph_window", "Depth First Search", nullptr));
        btnBFS->setText(QCoreApplication::translate("graph_window", "Breadth First Search", nullptr));
        btnBack->setText(QCoreApplication::translate("graph_window", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graph_window: public Ui_graph_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_WINDOW_H
