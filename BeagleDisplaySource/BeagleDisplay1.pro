#-------------------------------------------------
#
# Project created by QtCreator 2014-01-21T21:51:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BeagleDisplay1
TEMPLATE = app


SOURCES += main.cpp\
        rfidreader.cpp \
    Worker.cpp

HEADERS  += rfidreader.h \
    Worker.h

FORMS    += rfidreader.ui
