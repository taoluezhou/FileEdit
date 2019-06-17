#-------------------------------------------------
#
# Project created by QtCreator 2019-04-24T16:01:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PeFIT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    subwindow.cpp

HEADERS  += mainwindow.h \
    subwindow.h

FORMS    += mainwindow.ui \
    subwindow.ui

RESOURCES += \
    icon.qrc
