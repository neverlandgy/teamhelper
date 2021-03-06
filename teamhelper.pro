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
    punchout.cpp \
    addproject.cpp \
    team.cpp \
    draglistswidget.cpp \
    projectgrade.cpp \
    perslevel.cpp \
    persgrade.cpp \
    task.cpp \
    salary.cpp \
    salarydialog.cpp

HEADERS  += mainwindow.h \
    login.h \
    sqlconnection.h \
    about.h \
    myinfo.h \
    punchin.h \
    punchout.h \
    addproject.h \
    team.h \
    draglistswidget.h \
    projectgrade.h \
    perslevel.h \
    persgrade.h \
    task.h \
    salary.h \
    extern.h \
    salarydialog.h

FORMS    += mainwindow.ui \
    login.ui \
    about.ui \
    myinfo.ui \
    punchin.ui \
    punchout.ui \
    addproject.ui \
    team.ui \
    projectgrade.ui \
    perslevel.ui \
    persgrade.ui \
    task.ui \
    salary.ui \
    salarydialog.ui

RESOURCES += \
    res.qrc
