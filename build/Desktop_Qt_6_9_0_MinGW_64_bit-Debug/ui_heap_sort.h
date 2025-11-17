/********************************************************************************
** Form generated from reading UI file 'heap_sort.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEAP_SORT_H
#define UI_HEAP_SORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Heap_Sort
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblTitle;
    QHBoxLayout *horizontalLayout;
    QPushButton *btninsert;
    QPushButton *btnReset;
    QPushButton *btnRandomize;
    QPushButton *btnStart;
    QRadioButton *btnmaxheap;
    QRadioButton *btnminheap;
    QLabel *label;
    QLineEdit *lineSearchEdit;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QSlider *sliderSpeed;
    QSpacerItem *horizontalSpacer;
    QLabel *lblOperation;
    QPushButton *btnBack;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Heap_Sort)
    {
        if (Heap_Sort->objectName().isEmpty())
            Heap_Sort->setObjectName("Heap_Sort");
        Heap_Sort->resize(800, 600);
        Heap_Sort->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #1e1b4b,      /* Indigo */\n"
"        stop:0.5 #581c87,    /* Purple */\n"
"        stop:1 #831843       /* Pink */\n"
"    );\n"
"}"));
        centralwidget = new QWidget(Heap_Sort);
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
        btninsert = new QPushButton(centralwidget);
        btninsert->setObjectName("btninsert");
        btninsert->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        horizontalLayout->addWidget(btninsert);

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

        btnmaxheap = new QRadioButton(centralwidget);
        btnmaxheap->setObjectName("btnmaxheap");
        QFont font;
        font.setPointSize(12);
        btnmaxheap->setFont(font);
        btnmaxheap->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout->addWidget(btnmaxheap);

        btnminheap = new QRadioButton(centralwidget);
        btnminheap->setObjectName("btnminheap");
        btnminheap->setFont(font);
        btnminheap->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout->addWidget(btnminheap);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: \"Times New Roman\", \"Segoe UI\", Arial, sans-serif;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"	color: qlineargradient(\n"
"        spread:pad, \n"
"        x1:0, y1:0, x2:1, y2:0, \n"
"        stop:0 #ffffff\n"
"    );\n"
"    qproperty-alignment: AlignCenter;\n"
"    letter-spacing: 1px;\n"
"    text-transform: uppercase;\n"
"    background: transparent;\n"
"    padding: 5px;\n"
"}\n"
"\n"
""));

        verticalLayout->addWidget(label);

        lineSearchEdit = new QLineEdit(centralwidget);
        lineSearchEdit->setObjectName("lineSearchEdit");
        lineSearchEdit->setFont(font);
        lineSearchEdit->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout->addWidget(lineSearchEdit);

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

        Heap_Sort->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Heap_Sort);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Heap_Sort->setMenuBar(menubar);
        statusbar = new QStatusBar(Heap_Sort);
        statusbar->setObjectName("statusbar");
        Heap_Sort->setStatusBar(statusbar);

        retranslateUi(Heap_Sort);

        QMetaObject::connectSlotsByName(Heap_Sort);
    } // setupUi

    void retranslateUi(QMainWindow *Heap_Sort)
    {
        Heap_Sort->setWindowTitle(QCoreApplication::translate("Heap_Sort", "MainWindow", nullptr));
        lblTitle->setText(QCoreApplication::translate("Heap_Sort", "Heap Sort Visualization", nullptr));
        btninsert->setText(QCoreApplication::translate("Heap_Sort", "Insert", nullptr));
        btnReset->setText(QCoreApplication::translate("Heap_Sort", "Reset", nullptr));
        btnRandomize->setText(QCoreApplication::translate("Heap_Sort", "Randomize", nullptr));
        btnStart->setText(QCoreApplication::translate("Heap_Sort", "Start", nullptr));
        btnmaxheap->setText(QCoreApplication::translate("Heap_Sort", "Max heap", nullptr));
        btnminheap->setText(QCoreApplication::translate("Heap_Sort", "Min heap", nullptr));
        label->setText(QCoreApplication::translate("Heap_Sort", "Add new node in the tree :", nullptr));
        lblOperation->setText(QCoreApplication::translate("Heap_Sort", "TextLabel", nullptr));
        btnBack->setText(QCoreApplication::translate("Heap_Sort", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Heap_Sort: public Ui_Heap_Sort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEAP_SORT_H
