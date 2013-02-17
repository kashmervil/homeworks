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
    MapOfNet.cpp \
    networktest.cpp
HEADERS += \
    OS.h \
    MacOS.h \
    Linux.h \
    Windows.h \
    network.h \
    MapOfNet.h \
    RandState.h \
    networktest.h
# install
 target.path = $$[Network_testing]C:\Users\Alexander\Desktop\LocalNetwork-build-desktop-Qt_4_8_1_for_Desktop_-_MinGW__Qt_SDK_________
 sources.files = $$SOURCES *.pro
 sources.path = $$[QT_INSTALL_EXAMPLES]C:\Users\Alexander\Desktop\sdkjvn
INSTALLS += target sources

