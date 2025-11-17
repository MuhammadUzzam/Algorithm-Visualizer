QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    binary_search.cpp \
    bubble_sort.cpp \
    heap_sort.cpp \
    insertion_sort.cpp \
    linear_search.cpp \
    main.cpp \
    mainwindow.cpp \
    merge_sort.cpp \
    quick_sort.cpp \
    searching_window.cpp \
    selection_sort.cpp \
    sorting_window.cpp \
    dfs_window.cpp \
    bfs_window.cpp\
    graph_window.cpp

HEADERS += \
    binary_search.h \
    bubble_sort.h \
    heap_sort.h \
    insertion_sort.h \
    linear_search.h \
    mainwindow.h \
    merge_sort.h \
    quick_sort.h \
    searching_window.h \
    selection_sort.h \
    sorting_window.h \
    dfs_window.h \
    bfs_window.h\
    graph_window.h

FORMS += \
    binary_search.ui \
    bubble_sort.ui \
    heap_sort.ui \
    insertion_sort.ui \
    linear_search.ui \
    mainwindow.ui \
    merge_sort.ui \
    quick_sort.ui \
    searching_window.ui \
    selection_sort.ui \
    sorting_window.ui \
    dfs_window.ui \
    bfs_window.ui \
    graph_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
