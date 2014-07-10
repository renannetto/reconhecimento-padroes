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
    distancia.cpp \
    distanciaeuclides.cpp \
    distanciahamming.cpp \
    paletadecores.cpp \
    canvas.cpp \
    adicionarruido.cpp \
    removeratributos.cpp \
    agrupamentoarvore.cpp \
    distanciacluster.cpp \
    distanciacompleta.cpp \
    distanciasimples.cpp \
    kmeans.cpp \
    distanciamedia.cpp \
    distribuicaof.cpp \
    nododendograma.cpp

HEADERS  += mainwindow.h \
    ponto.h \
    conjuntodedados.h \
    distancia.h \
    distanciaeuclides.h \
    distanciahamming.h \
    paletadecores.h \
    canvas.h \
    adicionarruido.h \
    removeratributos.h \
    agrupamentoarvore.h \
    distanciacluster.h \
    distanciacompleta.h \
    distanciasimples.h \
    kmeans.h \
    distanciamedia.h \
    distribuicaof.h \
    nododendograma.h \
    anova.h

FORMS    += mainwindow.ui \
    adicionarruido.ui \
    removeratributos.ui
