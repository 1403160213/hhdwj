#-------------------------------------------------
#
# Project created by QtCreator 2016-11-20T15:07:48
#
#-------------------------------------------------

QT       += core gui
QT		+= charts network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = protect03
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    dataworker.cpp

HEADERS  += mainwidget.h \
    dataworker.h \ 
    common.h

FORMS    += mainwidget.ui

RC_ICONS = logo.ico

