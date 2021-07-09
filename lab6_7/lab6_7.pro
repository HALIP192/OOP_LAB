#-------------------------------------------------
#
# Project created by QtCreator 2021-06-06T13:21:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab6_7
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    abstarctreader.cpp \
    boss.cpp \
    csvexception.cpp \
    csvreader.cpp \
    date.cpp \
    errortextbrowser.cpp \
    jsonreader.cpp \
    person.cpp \
    personcsv.cpp \
    student.cpp \
    worker.cpp

HEADERS  += mainwindow.h \
    abstarctreader.h \
    boss.h \
    csvexception.h \
    csvreader.h \
    date.h \
    errortextbrowser.h \
    json.hpp \
    jsonreader.h \
    person.h \
    personcsv.h \
    student.h \
    worker.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    lab6_7.pro.user
CONFIG += c++11
