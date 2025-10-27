QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    binary_search.cpp \
    bubble_sort.cpp \
    graph_window.cpp \
    linear_search.cpp \
    main.cpp \
    mainwindow.cpp \
    searching_window.cpp \
    sorting_window.cpp

HEADERS += \
    binary_search.h \
    bubble_sort.h \
    graph_window.h \
    linear_search.h \
    mainwindow.h \
    searching_window.h \
    sorting_window.h

FORMS += \
    binary_search.ui \
    bubble_sort.ui \
    graph_window.ui \
    linear_search.ui \
    mainwindow.ui \
    searching_window.ui \
    sorting_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
