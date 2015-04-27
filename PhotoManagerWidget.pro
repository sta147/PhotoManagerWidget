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

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui

unix:INCLUDEPATH += "/Users/kayani/Downloads/opencv-3.0.0-rc1/staticLibs/include"
LIBS += -L/Users/kayani/Downloads/opencv-3.0.0-rc1 \
    libopencv_core240d \
    libopencv_highgui240d \
    libopencv_imgproc240d \
    libopencv_features2d240d \
    libopencv_calib3d240d \


SOURCES += main.cpp\
        photomanager.cpp \
    slideshow.cpp

HEADERS  += photomanager.h \
    slideshow.h

FORMS    += photomanager.ui \
    slideshow.ui
CONFIG += console

CONFIG += gui

QT += core
