#-------------------------------------------------
#
# Project created by QtCreator 2014-03-17T11:06:30
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = teamhelper
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    login.cpp \
    sqlconnection.cpp \
    about.cpp \
    myinfo.cpp \
    punchin.cpp \
    punchout.cpp

HEADERS  += mainwindow.h \
    login.h \
    sqlconnection.h \
    about.h \
    myinfo.h \
    punchin.h \
    punchout.h

FORMS    += mainwindow.ui \
    login.ui \
    about.ui \
    myinfo.ui \
    punchin.ui \
    punchout.ui

RESOURCES += \
    res.qrc
