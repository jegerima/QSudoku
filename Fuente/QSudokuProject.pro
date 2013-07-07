#-------------------------------------------------
#
# Project created by QtCreator 2013-06-05T10:09:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSudokuProject
TEMPLATE = app


SOURCES += main.cpp\
        maintable.cpp \
    celda.cpp \
    genmatriz.cpp \
    guardar.cpp \
    simplecrypt.cpp \
    nivel.cpp \
    about.cpp

HEADERS  += maintable.h \
    celda.h \
    genmatriz.h \
    simplecrypt.h \
    guardar.h \
    nivel.h \
    about.h

FORMS    += maintable.ui \
    nivel.ui \
    about.ui

RESOURCES += \
    images.qrc
