#-------------------------------------------------
#
# Project created by QtCreator 2014-05-22T10:51:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Drag_Drop
TEMPLATE = app


SOURCES += main.cpp\
    drop.cpp \
    drag.cpp

HEADERS  += \
    drop.h \
    drag.h

FORMS    += drag_drop.ui

RESOURCES += \
    images.qrc
