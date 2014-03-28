#-------------------------------------------------
#
# Project created by QtCreator 2014-03-28T18:29:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = reconhecimento-padroes
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ponto.cpp \
    conjuntodedados.cpp \
    espiralsimples.cpp \
    geracaoespiral.cpp

HEADERS  += mainwindow.h \
    ponto.h \
    conjuntodedados.h \
    espiralsimples.h \
    geracaoespiral.h

FORMS    += mainwindow.ui \
    geracaoespiral.ui
