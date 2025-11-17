/********************************************************************************
** Form generated from reading UI file 'quick_sort.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUICK_SORT_H
#define UI_QUICK_SORT_H

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

class Ui_Quick_Sort
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
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

    void setupUi(QMainWindow *Quick_Sort)
    {
        if (Quick_Sort->objectName().isEmpty())
            Quick_Sort->setObjectName("Quick_Sort");
        Quick_Sort->resize(800, 600);
        Quick_Sort->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #1e1b4b,      /* Indigo */\n"
"        stop:0.5 #581c87,    /* Purple */\n"
"        stop:1 #831843       /* Pink */\n"
"    );\n"
"}"));
        centralwidget = new QWidget(Quick_Sort);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        lblTitle = new QLabel(centralwidget);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setStyleSheet(QString::fromUtf8("QLabel {\n"
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

        verticalLayout->addWidget(lblTitle);

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


        verticalLayout->addLayout(horizontalLayout);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        verticalLayout->addWidget(graphicsView);

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


        verticalLayout->addLayout(horizontalLayout_2);

        Quick_Sort->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Quick_Sort);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        Quick_Sort->setMenuBar(menubar);
        statusbar = new QStatusBar(Quick_Sort);
        statusbar->setObjectName("statusbar");
        Quick_Sort->setStatusBar(statusbar);

        retranslateUi(Quick_Sort);

        QMetaObject::connectSlotsByName(Quick_Sort);
    } // setupUi

    void retranslateUi(QMainWindow *Quick_Sort)
    {
        Quick_Sort->setWindowTitle(QCoreApplication::translate("Quick_Sort", "MainWindow", nullptr));
        lblTitle->setText(QCoreApplication::translate("Quick_Sort", "Quick Sort Visualization", nullptr));
        btnReset->setText(QCoreApplication::translate("Quick_Sort", "Reset", nullptr));
        btnRandomize->setText(QCoreApplication::translate("Quick_Sort", "Randomize", nullptr));
        btnPause->setText(QCoreApplication::translate("Quick_Sort", "Pause", nullptr));
        btnStart->setText(QCoreApplication::translate("Quick_Sort", "Start", nullptr));
        lblOperation->setText(QCoreApplication::translate("Quick_Sort", "TextLabel", nullptr));
        btnBack->setText(QCoreApplication::translate("Quick_Sort", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Quick_Sort: public Ui_Quick_Sort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUICK_SORT_H
