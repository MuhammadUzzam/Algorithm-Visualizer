/********************************************************************************
** Form generated from reading UI file 'sorting_window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTING_WINDOW_H
#define UI_SORTING_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sorting_window
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *btnsquickSort_3;
    QPushButton *btnmergeSort;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnheapSort;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btnInsertionSort;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnBubbleSort;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnselectionSort;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *sorting_window)
    {
        if (sorting_window->objectName().isEmpty())
            sorting_window->setObjectName("sorting_window");
        sorting_window->resize(618, 600);
        sorting_window->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #1e1b4b,      /* Indigo */\n"
"        stop:0.5 #581c87,    /* Purple */\n"
"        stop:1 #831843       /* Pink */\n"
"    );\n"
"}"));
        centralwidget = new QWidget(sorting_window);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        btnsquickSort_3 = new QPushButton(centralwidget);
        btnsquickSort_3->setObjectName("btnsquickSort_3");
        btnsquickSort_3->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        gridLayout->addWidget(btnsquickSort_3, 0, 3, 1, 2);

        btnmergeSort = new QPushButton(centralwidget);
        btnmergeSort->setObjectName("btnmergeSort");
        btnmergeSort->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        gridLayout->addWidget(btnmergeSort, 1, 3, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(144, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        btnheapSort = new QPushButton(centralwidget);
        btnheapSort->setObjectName("btnheapSort");
        btnheapSort->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        gridLayout->addWidget(btnheapSort, 2, 3, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(218, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 3, 0, 1, 2);

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

        gridLayout->addWidget(btnBack, 3, 2, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(223, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 3, 4, 1, 1);

        btnInsertionSort = new QPushButton(centralwidget);
        btnInsertionSort->setObjectName("btnInsertionSort");
        btnInsertionSort->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        gridLayout->addWidget(btnInsertionSort, 2, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(144, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        btnBubbleSort = new QPushButton(centralwidget);
        btnBubbleSort->setObjectName("btnBubbleSort");
        btnBubbleSort->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        gridLayout->addWidget(btnBubbleSort, 1, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(144, 37, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        btnselectionSort = new QPushButton(centralwidget);
        btnselectionSort->setObjectName("btnselectionSort");
        btnselectionSort->setEnabled(true);
        btnselectionSort->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        gridLayout->addWidget(btnselectionSort, 0, 0, 1, 2);

        sorting_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(sorting_window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 618, 18));
        sorting_window->setMenuBar(menubar);
        statusbar = new QStatusBar(sorting_window);
        statusbar->setObjectName("statusbar");
        sorting_window->setStatusBar(statusbar);

        retranslateUi(sorting_window);

        QMetaObject::connectSlotsByName(sorting_window);
    } // setupUi

    void retranslateUi(QMainWindow *sorting_window)
    {
        sorting_window->setWindowTitle(QCoreApplication::translate("sorting_window", "MainWindow", nullptr));
        btnsquickSort_3->setText(QCoreApplication::translate("sorting_window", "Quick Sort", nullptr));
        btnmergeSort->setText(QCoreApplication::translate("sorting_window", "Merge Sort", nullptr));
        btnheapSort->setText(QCoreApplication::translate("sorting_window", "Heap sort", nullptr));
        btnBack->setText(QCoreApplication::translate("sorting_window", "back", nullptr));
        btnInsertionSort->setText(QCoreApplication::translate("sorting_window", "Insertion Sort", nullptr));
        btnBubbleSort->setText(QCoreApplication::translate("sorting_window", "Bubble Sort", nullptr));
        btnselectionSort->setText(QCoreApplication::translate("sorting_window", "Selection Sort", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sorting_window: public Ui_sorting_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTING_WINDOW_H
