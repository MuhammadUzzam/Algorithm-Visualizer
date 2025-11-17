/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGraph;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSorting;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSearching;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(766, 606);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #1e1b4b,      /* Indigo */\n"
"        stop:0.5 #581c87,    /* Purple */\n"
"        stop:1 #831843       /* Pink */\n"
"    );\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: \"Rockwell\", \"Segoe UI\", Arial, sans-serif;\n"
"    font-size: 30px;\n"
"    font-weight: bold;\n"
"	color: qlineargradient(\n"
"        spread:pad, \n"
"        x1:0, y1:0, x2:1, y2:0, \n"
"        stop:0 #0077b6, stop:1 #48cae4\n"
"    );\n"
"\n"
"    qproperty-alignment: AlignCenter;\n"
"    letter-spacing: 1px;\n"
"    text-transform: uppercase;\n"
"    background: transparent;\n"
"    padding: 5px;\n"
"}\n"
""));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnGraph = new QPushButton(centralwidget);
        btnGraph->setObjectName("btnGraph");
        btnGraph->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
"        background: qlineargradient(stop:0 #10b981, stop:1 #059669);\n"
"        color: white;\n"
"        font-size: 18px;\n"
"        font-weight: 700;\n"
"        border: none;\n"
"        border-radius: 20px;\n"
"        padding: 12px 24px;\n"
"        transition: all 0.3s ease;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background: qlineargradient(stop:0 #059669, stop:1 #047857);\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background: qlineargradient(stop:0 #047857, stop:1 #065f46);\n"
"        padding: 14px 24px 10px 24px;\n"
"    }"));

        horizontalLayout->addWidget(btnGraph);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSorting = new QPushButton(centralwidget);
        btnSorting->setObjectName("btnSorting");
        btnSorting->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
"        background: qlineargradient(stop:0 #10b981, stop:1 #059669);\n"
"        color: white;\n"
"        font-size: 18px;\n"
"        font-weight: 700;\n"
"        border: none;\n"
"        border-radius: 20px;\n"
"        padding: 12px 24px;\n"
"        transition: all 0.3s ease;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background: qlineargradient(stop:0 #059669, stop:1 #047857);\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background: qlineargradient(stop:0 #047857, stop:1 #065f46);\n"
"        padding: 14px 24px 10px 24px;\n"
"    }"));

        horizontalLayout->addWidget(btnSorting);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnSearching = new QPushButton(centralwidget);
        btnSearching->setObjectName("btnSearching");
        btnSearching->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
"        background: qlineargradient(stop:0 #10b981, stop:1 #059669);\n"
"        color: white;\n"
"        font-size: 18px;\n"
"        font-weight: 700;\n"
"        border: none;\n"
"        border-radius: 20px;\n"
"        padding: 12px 24px;\n"
"        transition: all 0.3s ease;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background: qlineargradient(stop:0 #059669, stop:1 #047857);\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background: qlineargradient(stop:0 #047857, stop:1 #065f46);\n"
"        padding: 14px 24px 10px 24px;\n"
"    }"));

        horizontalLayout->addWidget(btnSearching);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 766, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Algorithm Visualizer", nullptr));
        btnGraph->setText(QCoreApplication::translate("MainWindow", "Graph Algorithms", nullptr));
        btnSorting->setText(QCoreApplication::translate("MainWindow", "Sorting Algorithms", nullptr));
        btnSearching->setText(QCoreApplication::translate("MainWindow", "Searching Algorithms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
