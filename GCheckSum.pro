#-------------------------------------------------
#
# Project created by QtCreator 2015-02-05T12:43:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gchecksum

CONFIG += release

VERSION = 0.1

TEMPLATE = app

SOURCES += src/main.cpp\
        src/gchecksum.cpp \
        src/gsumwidget.cpp

HEADERS  += src/gchecksum.h \
        src/gsumwidget.h

FORMS    += forms/gchecksum.ui

RESOURCES += \
    resource.qrc
    
DESTDIR = build/target/
OBJECTS_DIR = build/obj/
MOC_DIR = build/moc/
RCC_DIR = build/rcc/
UI_DIR = build/uic

DISTFILES = AUTHORS COPYING CHANGELOG
