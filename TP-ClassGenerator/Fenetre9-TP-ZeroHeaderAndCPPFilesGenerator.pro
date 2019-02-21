QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nomprojet
TEMPLATE = app


SOURCES += main.cpp \
    window.cpp \
    modalwindow.cpp

HEADERS += \
    window.h \
    modalwindow.h
