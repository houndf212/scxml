#-------------------------------------------------
#
# Project created by QtCreator 2017-02-22T16:27:58
#
#-------------------------------------------------

QT       += core gui scxml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = scxml_test
TEMPLATE = app

win32::msvc*{ QMAKE_CXXFLAGS_WARN_ON += -we"4244" }

#QMAKE_CFLAGS_WARN_ON = -W4
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#STATECHARTS += light.scxml

SOURCES += main.cpp \
    lightwidget.cpp \
    trafficwidget.cpp \
    stopwatchwidget.cpp

HEADERS  += \
    lightwidget.h \
    trafficwidget.h \
    stopwatchwidget.h

FORMS    +=

RESOURCES += \
    res.qrc

STATECHARTS +=
