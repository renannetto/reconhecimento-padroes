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
    geracaoespiral.cpp \
    conjuntoaleatorio.cpp \
    distancia.cpp \
    distanciaeuclides.cpp \
    distanciahamming.cpp \
    geracaoaleatorio.cpp \
    nearestneighbor.cpp \
    paletadecores.cpp \
    canvas.cpp \
    espiraldupla.cpp \
    classificador.cpp \
    ibl.cpp \
    ibl1.cpp \
    ibl2.cpp

HEADERS  += mainwindow.h \
    ponto.h \
    conjuntodedados.h \
    espiralsimples.h \
    geracaoespiral.h \
    conjuntoaleatorio.h \
    distancia.h \
    distanciaeuclides.h \
    distanciahamming.h \
    geracaoaleatorio.h \
    nearestneighbor.h \
    paletadecores.h \
    canvas.h \
    espiraldupla.h \
    classificador.h \
    ibl.h \
    ibl1.h \
    ibl2.h

FORMS    += mainwindow.ui \
    geracaoespiral.ui \
    geracaoaleatorio.ui
