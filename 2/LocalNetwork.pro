#-------------------------------------------------
#
# Project created by QtCreator 2012-10-17T09:48:58
#
#-------------------------------------------------
QT       += core\
            testlib

QT       -= gui

TARGET   += Network
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    network.cpp \
    main.cpp \
    MapOfNet.cpp
HEADERS += \
    OS.h \
    MacOS.h \
    Linux.h \
    Windows.h \
    network.h \
    MapOfNet.h
