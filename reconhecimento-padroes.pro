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
    paletadecores.cpp \
    canvas.cpp \
    espiraldupla.cpp \
    adicionarruido.cpp \
    removeratributos.cpp \
    agrupador.cpp \
    agrupamentoarvore.cpp \
    distanciacluster.cpp \
    distanciacompleta.cpp \
    distanciasimples.cpp \
    kmeans.cpp \
    distanciamedia.cpp \
    distribuicaof.cpp

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
    paletadecores.h \
    canvas.h \
    espiraldupla.h \
    adicionarruido.h \
    removeratributos.h \
    agrupador.h \
    agrupamentoarvore.h \
    distanciacluster.h \
    distanciacompleta.h \
    distanciasimples.h \
    kmeans.h \
    distanciamedia.h \
    distribuicaof.h

FORMS    += mainwindow.ui \
    geracaoespiral.ui \
    geracaoaleatorio.ui \
    adicionarruido.ui \
    removeratributos.ui
