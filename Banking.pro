#-------------------------------------------------
#
# Project created by QtCreator 2017-07-20T08:47:06
#
#-------------------------------------------------

QT       += core gui xml

CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Banking
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sort.cpp \
    sortfactory.cpp \
    sortinsertion.cpp \
    sortselection.cpp \
    transaction.cpp \
    transactionhandler.cpp \
    transactionlist.cpp \
    transactionReader.cpp \
    transactionWriter.cpp \
    abstractfactory.cpp

HEADERS  += mainwindow.h \
    abstractfactory.h \
    sort.h \
    sortfactory.h \
    sortinsertion.h \
    sortselection.h \
    transaction.h \
    transactionhandler.h \
    transactionlist.h \
    transactionReader.h \
    transactionWriter.h
