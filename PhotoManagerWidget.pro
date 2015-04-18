#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T05:10:37
#
#-------------------------------------------------

QT       += core gui
QT += widgets
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PhotoManagerWidget
TEMPLATE = app


SOURCES += main.cpp\
        photomanager.cpp \
    slideshow.cpp

HEADERS  += photomanager.h \
    slideshow.h

FORMS    += photomanager.ui \
    slideshow.ui
