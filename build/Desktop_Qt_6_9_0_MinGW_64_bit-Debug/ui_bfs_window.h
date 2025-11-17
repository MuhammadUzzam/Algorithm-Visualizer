/********************************************************************************
** Form generated from reading UI file 'bfs_window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BFS_WINDOW_H
#define UI_BFS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bfs_window
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QSpinBox *spinNodeCount;
    QSlider *speedSlider;
    QPushButton *btnRunBFS;
    QPushButton *btnAddEdge;
    QPushButton *btnAddNode;
    QPushButton *btnClearGraph;
    QPushButton *btnRemoveNode;
    QPushButton *btnRandomGraph;
    QPushButton *btnBack;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *bfs_window)
    {
        if (bfs_window->objectName().isEmpty())
            bfs_window->setObjectName("bfs_window");
        bfs_window->resize(800, 600);
        centralwidget = new QWidget(bfs_window);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
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
"    qproperty-alignment: AlignCenter;\n"
"    letter-spacing: 1px;\n"
"    text-transform: uppercase;\n"
"    background: transparent;\n"
"    padding: 5px;\n"
"}\n"
"\n"
""));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        horizontalLayout->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        spinNodeCount = new QSpinBox(centralwidget);
        spinNodeCount->setObjectName("spinNodeCount");
        spinNodeCount->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    background-color: qlineargradient(stop:0 #10b981, stop:1 #059669);\n"
"    color: white;\n"
"    font-size: 20px;\n"
"    font-weight: 700;\n"
"}\n"
"\n"
"/* Hover */\n"
"QSpinBox:hover {\n"
"    background-color: #059669;\n"
"}\n"
"\n"
"/* Pressed */\n"
"QSpinBox:pressed {\n"
"    background-color: #047857;\n"
"}"));
        spinNodeCount->setMinimum(1);
        spinNodeCount->setMaximum(50);
        spinNodeCount->setValue(6);

        verticalLayout->addWidget(spinNodeCount);

        speedSlider = new QSlider(centralwidget);
        speedSlider->setObjectName("speedSlider");
        speedSlider->setMinimum(100);
        speedSlider->setMaximum(1000);
        speedSlider->setValue(500);
        speedSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout->addWidget(speedSlider);

        btnRunBFS = new QPushButton(centralwidget);
        btnRunBFS->setObjectName("btnRunBFS");
        btnRunBFS->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
"        background: qlineargradient(stop:0 #10b981, stop:1 #059669);\n"
"        color: white;\n"
"        font-size: 14px;\n"
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

        verticalLayout->addWidget(btnRunBFS);

        btnAddEdge = new QPushButton(centralwidget);
        btnAddEdge->setObjectName("btnAddEdge");
        btnAddEdge->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
"        background: qlineargradient(stop:0 #10b981, stop:1 #059669);\n"
"        color: white;\n"
"        font-size: 14px;\n"
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

        verticalLayout->addWidget(btnAddEdge);

        btnAddNode = new QPushButton(centralwidget);
        btnAddNode->setObjectName("btnAddNode");
        btnAddNode->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
"        background: qlineargradient(stop:0 #10b981, stop:1 #059669);\n"
"        color: white;\n"
"        font-size: 14px;\n"
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

        verticalLayout->addWidget(btnAddNode);

        btnClearGraph = new QPushButton(centralwidget);
        btnClearGraph->setObjectName("btnClearGraph");
        btnClearGraph->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
"        background: qlineargradient(stop:0 #10b981, stop:1 #059669);\n"
"        color: white;\n"
"        font-size: 14px;\n"
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

        verticalLayout->addWidget(btnClearGraph);

        btnRemoveNode = new QPushButton(centralwidget);
        btnRemoveNode->setObjectName("btnRemoveNode");
        btnRemoveNode->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
"        background: qlineargradient(stop:0 #10b981, stop:1 #059669);\n"
"        color: white;\n"
"        font-size: 14px;\n"
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

        verticalLayout->addWidget(btnRemoveNode);

        btnRandomGraph = new QPushButton(centralwidget);
        btnRandomGraph->setObjectName("btnRandomGraph");
        btnRandomGraph->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
"        background: qlineargradient(stop:0 #10b981, stop:1 #059669);\n"
"        color: white;\n"
"        font-size: 14px;\n"
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

        verticalLayout->addWidget(btnRandomGraph);

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


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(1, 2);

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        bfs_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(bfs_window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        bfs_window->setMenuBar(menubar);
        statusbar = new QStatusBar(bfs_window);
        statusbar->setObjectName("statusbar");
        bfs_window->setStatusBar(statusbar);

        retranslateUi(bfs_window);

        QMetaObject::connectSlotsByName(bfs_window);
    } // setupUi

    void retranslateUi(QMainWindow *bfs_window)
    {
        bfs_window->setWindowTitle(QCoreApplication::translate("bfs_window", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("bfs_window", "Breadth First Search Visualization", nullptr));
        btnRunBFS->setText(QCoreApplication::translate("bfs_window", "Run BFS", nullptr));
        btnAddEdge->setText(QCoreApplication::translate("bfs_window", "Add Edge", nullptr));
        btnAddNode->setText(QCoreApplication::translate("bfs_window", "Add Node", nullptr));
        btnClearGraph->setText(QCoreApplication::translate("bfs_window", "Clear Graph", nullptr));
        btnRemoveNode->setText(QCoreApplication::translate("bfs_window", "Remove Node", nullptr));
        btnRandomGraph->setText(QCoreApplication::translate("bfs_window", "Random Graph", nullptr));
        btnBack->setText(QCoreApplication::translate("bfs_window", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bfs_window: public Ui_bfs_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BFS_WINDOW_H
