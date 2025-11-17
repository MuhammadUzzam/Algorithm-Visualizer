/********************************************************************************
** Form generated from reading UI file 'selection_sort.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTION_SORT_H
#define UI_SELECTION_SORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Selection_sort
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblTitle;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnReset;
    QPushButton *btnRandomize;
    QPushButton *btnPause;
    QPushButton *btnStart;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QSlider *sliderSpeed;
    QSpacerItem *horizontalSpacer;
    QLabel *lblOperation;
    QPushButton *btnBack;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Selection_sort)
    {
        if (Selection_sort->objectName().isEmpty())
            Selection_sort->setObjectName("Selection_sort");
        Selection_sort->resize(800, 600);
        Selection_sort->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #1e1b4b,      /* Indigo */\n"
"        stop:0.5 #581c87,    /* Purple */\n"
"        stop:1 #831843       /* Pink */\n"
"    );\n"
"}"));
        centralwidget = new QWidget(Selection_sort);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        lblTitle = new QLabel(centralwidget);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: \"Rockwell\", \"Segoe UI\", Arial, sans-serif;\n"
"    font-size: 28px;\n"
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

        verticalLayout_2->addWidget(lblTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnReset = new QPushButton(centralwidget);
        btnReset->setObjectName("btnReset");
        btnReset->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        horizontalLayout->addWidget(btnReset);

        btnRandomize = new QPushButton(centralwidget);
        btnRandomize->setObjectName("btnRandomize");
        btnRandomize->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        horizontalLayout->addWidget(btnRandomize);

        btnPause = new QPushButton(centralwidget);
        btnPause->setObjectName("btnPause");
        btnPause->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        horizontalLayout->addWidget(btnPause);

        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName("btnStart");
        btnStart->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        horizontalLayout->addWidget(btnStart);


        verticalLayout_2->addLayout(horizontalLayout);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        verticalLayout_2->addWidget(graphicsView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        sliderSpeed = new QSlider(centralwidget);
        sliderSpeed->setObjectName("sliderSpeed");
        sliderSpeed->setMinimumSize(QSize(211, 41));
        sliderSpeed->setMinimum(100);
        sliderSpeed->setMaximum(1000);
        sliderSpeed->setValue(500);
        sliderSpeed->setOrientation(Qt::Orientation::Horizontal);
        sliderSpeed->setTickPosition(QSlider::TickPosition::TicksBelow);
        sliderSpeed->setTickInterval(100);

        horizontalLayout_2->addWidget(sliderSpeed);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lblOperation = new QLabel(centralwidget);
        lblOperation->setObjectName("lblOperation");
        lblOperation->setStyleSheet(QString::fromUtf8("  QLabel {\n"
"        font-family: \"Segoe UI\", Arial, sans-serif;\n"
"        font-size: 14px;\n"
"        font-weight: bold;\n"
"        color: qlineargradient(\n"
"            spread:pad,\n"
"            x1:0, y1:0, x2:1, y2:0,\n"
"            stop:0 #00ffff, stop:1 #00dddd\n"
"        );\n"
"        qproperty-alignment: AlignCenter;\n"
"        letter-spacing: 1px;\n"
"        background: transparent;\n"
"        padding: 5px;\n"
"    }"));

        horizontalLayout_2->addWidget(lblOperation);

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

        horizontalLayout_2->addWidget(btnBack);


        verticalLayout_2->addLayout(horizontalLayout_2);

        Selection_sort->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Selection_sort);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        Selection_sort->setMenuBar(menubar);
        statusbar = new QStatusBar(Selection_sort);
        statusbar->setObjectName("statusbar");
        Selection_sort->setStatusBar(statusbar);

        retranslateUi(Selection_sort);

        QMetaObject::connectSlotsByName(Selection_sort);
    } // setupUi

    void retranslateUi(QMainWindow *Selection_sort)
    {
        Selection_sort->setWindowTitle(QCoreApplication::translate("Selection_sort", "MainWindow", nullptr));
        lblTitle->setText(QCoreApplication::translate("Selection_sort", "Selection Sort Visualization", nullptr));
        btnReset->setText(QCoreApplication::translate("Selection_sort", "Reset", nullptr));
        btnRandomize->setText(QCoreApplication::translate("Selection_sort", "Randomize", nullptr));
        btnPause->setText(QCoreApplication::translate("Selection_sort", "Pause", nullptr));
        btnStart->setText(QCoreApplication::translate("Selection_sort", "Start", nullptr));
        lblOperation->setText(QCoreApplication::translate("Selection_sort", "TextLabel", nullptr));
        btnBack->setText(QCoreApplication::translate("Selection_sort", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Selection_sort: public Ui_Selection_sort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTION_SORT_H
