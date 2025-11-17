/********************************************************************************
** Form generated from reading UI file 'linear_search.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEAR_SEARCH_H
#define UI_LINEAR_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_linear_search
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblTitle;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnResetlin;
    QPushButton *btnRandomizelin;
    QPushButton *btnPauselin;
    QPushButton *btnsearchlin;
    QLineEdit *lineSearchEdit;
    QLabel *label;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QSlider *sliderSpeed;
    QSpacerItem *horizontalSpacer;
    QLabel *lblOperation;
    QPushButton *btnBacklin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *linear_search)
    {
        if (linear_search->objectName().isEmpty())
            linear_search->setObjectName("linear_search");
        linear_search->resize(800, 600);
        QFont font;
        font.setPointSize(12);
        linear_search->setFont(font);
        linear_search->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #1e1b4b,      /* Indigo */\n"
"        stop:0.5 #581c87,    /* Purple */\n"
"        stop:1 #831843       /* Pink */\n"
"    );\n"
"}"));
        centralwidget = new QWidget(linear_search);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
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

        verticalLayout->addWidget(lblTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnResetlin = new QPushButton(centralwidget);
        btnResetlin->setObjectName("btnResetlin");
        btnResetlin->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        horizontalLayout->addWidget(btnResetlin);

        btnRandomizelin = new QPushButton(centralwidget);
        btnRandomizelin->setObjectName("btnRandomizelin");
        btnRandomizelin->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        horizontalLayout->addWidget(btnRandomizelin);

        btnPauselin = new QPushButton(centralwidget);
        btnPauselin->setObjectName("btnPauselin");
        btnPauselin->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        horizontalLayout->addWidget(btnPauselin);

        btnsearchlin = new QPushButton(centralwidget);
        btnsearchlin->setObjectName("btnsearchlin");
        btnsearchlin->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
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

        horizontalLayout->addWidget(btnsearchlin);


        verticalLayout->addLayout(horizontalLayout);

        lineSearchEdit = new QLineEdit(centralwidget);
        lineSearchEdit->setObjectName("lineSearchEdit");
        lineSearchEdit->setFont(font);
        lineSearchEdit->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout->addWidget(lineSearchEdit);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: \"Times New Roman\", \"Segoe UI\", Arial, sans-serif;\n"
"    font-size: 12px;\n"
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

        btnBacklin = new QPushButton(centralwidget);
        btnBacklin->setObjectName("btnBacklin");
        btnBacklin->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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

        horizontalLayout_2->addWidget(btnBacklin);


        verticalLayout->addLayout(horizontalLayout_2);

        linear_search->setCentralWidget(centralwidget);
        menubar = new QMenuBar(linear_search);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        linear_search->setMenuBar(menubar);
        statusbar = new QStatusBar(linear_search);
        statusbar->setObjectName("statusbar");
        linear_search->setStatusBar(statusbar);

        retranslateUi(linear_search);

        QMetaObject::connectSlotsByName(linear_search);
    } // setupUi

    void retranslateUi(QMainWindow *linear_search)
    {
        linear_search->setWindowTitle(QCoreApplication::translate("linear_search", "MainWindow", nullptr));
        lblTitle->setText(QCoreApplication::translate("linear_search", "Linear Search Algorithm Visualization", nullptr));
        btnResetlin->setText(QCoreApplication::translate("linear_search", "Reset", nullptr));
        btnRandomizelin->setText(QCoreApplication::translate("linear_search", "Randomize", nullptr));
        btnPauselin->setText(QCoreApplication::translate("linear_search", "Pause", nullptr));
        btnsearchlin->setText(QCoreApplication::translate("linear_search", "Search", nullptr));
        label->setText(QCoreApplication::translate("linear_search", "Enter the number you want to search :", nullptr));
        lblOperation->setText(QCoreApplication::translate("linear_search", "TextLabel", nullptr));
        btnBacklin->setText(QCoreApplication::translate("linear_search", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class linear_search: public Ui_linear_search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEAR_SEARCH_H
