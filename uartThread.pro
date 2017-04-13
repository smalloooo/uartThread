#-------------------------------------------------
#
# Project created by QtCreator 2017-04-13T08:42:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uartThread
TEMPLATE = app

CONFIG += serialport

SOURCES += main.cpp\
        mainwindow.cpp \
    uartthread.cpp \
    support.cpp

HEADERS  += mainwindow.h \
    uartthread.h \
    support.h

FORMS    += mainwindow.ui
