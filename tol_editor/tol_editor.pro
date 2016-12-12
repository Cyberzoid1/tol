#-------------------------------------------------
#
# Project created by QtCreator 2016-11-11T13:01:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tol_editor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    editorwindow.cpp \
    frameelement.cpp \
    animation.cpp \
    cell.cpp \
    frame.cpp \
    input.cpp \
    outputfile.cpp \
    toolbox.cpp \
    RGB.cpp

HEADERS  += mainwindow.h \
    editorwindow.h \
    frameelement.h \
    RGB.h \
    animation.h \
    cell.h \
    frame.h \
    input.h \
    outputfile.h \
    toolbox.h

FORMS    += mainwindow.ui \
editorwindow.ui
