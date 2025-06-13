#-------------------------------------------------
#
# Project created by QtCreator 2025-05-28T11:39:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LOCATION_ET_VENTE_MAISON
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    maison.cpp \
    tablehachage.cpp \
    maisonform.cpp \
    maisonviewer.cpp \
    maisonlisteviewer.cpp

HEADERS  += mainwindow.h \
    maison.h \
    tablehachage.h \
    maisonform.h \
    maisonviewer.h \
    maisonlisteviewer.h

FORMS    += \
    maisonform.ui \
    mainwindow.ui \
    maisonviewer.ui \
    maisonlisteviewer.ui
# ✅ Active les fonctionnalités modernes du C++ (comme for(:), auto, nullptr, etc.)
CONFIG += c++11
