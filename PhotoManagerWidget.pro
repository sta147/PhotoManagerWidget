#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T05:10:37
#
#-------------------------------------------------

QT       += core gui
QT += widgets
QT += multimedia



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.10
TARGET = PhotoManagerWidget
TEMPLATE = app

INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_objdetect -lopencv_calib3d -v
INCLUDEPATH += /opt/local/include
INCLUDEPATH += /Users/kayani/Downloads/opencv-3.0.0-rc1/modules/core/include


SOURCES += main.cpp\
        photomanager.cpp \
    slideshow.cpp


HEADERS  += photomanager.h \
    slideshow.h

FORMS    += photomanager.ui \
    slideshow.ui
CONFIG += console

CONFIG += gui

CONFIG += qt


QT += core



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/Cellar/exiv2/0.24/lib/release/ -lexiv2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/Cellar/exiv2/0.24/lib/debug/ -lexiv2
else:unix: LIBS += -L$$PWD/../../../usr/local/Cellar/exiv2/0.24/lib/ -lexiv2

INCLUDEPATH += $$PWD/../../../usr/local/Cellar/exiv2/0.24/include
DEPENDPATH += $$PWD/../../../usr/local/Cellar/exiv2/0.24/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/Cellar/exiv2/0.24/lib/release/libexiv2.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/Cellar/exiv2/0.24/lib/debug/libexiv2.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/Cellar/exiv2/0.24/lib/release/exiv2.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/Cellar/exiv2/0.24/lib/debug/exiv2.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../usr/local/Cellar/exiv2/0.24/lib/libexiv2.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/release/ -lopencv_core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/debug/ -lopencv_core
else:unix: LIBS += -L$$PWD/../../../usr/local/lib/ -lopencv_core

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/libopencv_core.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/libopencv_core.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/opencv_core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/opencv_core.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/libopencv_core.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/release/ -lopencv_imgproc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/debug/ -lopencv_imgproc
else:unix: LIBS += -L$$PWD/../../../usr/local/lib/ -lopencv_imgproc

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/libopencv_imgproc.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/libopencv_imgproc.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/opencv_imgproc.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/opencv_imgproc.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/libopencv_imgproc.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/release/ -lopencv_highgui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/debug/ -lopencv_highgui
else:unix: LIBS += -L$$PWD/../../../usr/local/lib/ -lopencv_highgui

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/libopencv_highgui.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/libopencv_highgui.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/opencv_highgui.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/opencv_highgui.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/libopencv_highgui.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/release/ -lopencv_ml
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/debug/ -lopencv_ml
else:unix: LIBS += -L$$PWD/../../../usr/local/lib/ -lopencv_ml

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/libopencv_ml.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/libopencv_ml.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/opencv_ml.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/opencv_ml.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/libopencv_ml.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/release/ -lopencv_video
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/debug/ -lopencv_video
else:unix: LIBS += -L$$PWD/../../../usr/local/lib/ -lopencv_video

INCLUDEPATH += $$PWD/../../../usr/local/include
DEPENDPATH += $$PWD/../../../usr/local/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/libopencv_video.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/libopencv_video.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/opencv_video.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/opencv_video.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/libopencv_video.a
