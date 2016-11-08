#-------------------------------------------------
#
# Project created by QtCreator 2016-11-08T09:37:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Toolbox
TEMPLATE = app


SOURCES += main.cpp\
        toolbox.cpp \
    colorwheel.cpp \
    colorpalette.cpp

HEADERS  += toolbox.h \
    colorwheel.h \
    colorpalette.h

FORMS    += toolbox.ui
