#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>
#include <iostream>
#include <QWheelEvent>

#include "ponto.h"

using namespace std;

class MainWindow;
class Canvas : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = 0);
    void fixarMainWindow(MainWindow * main_window);
    void desenharPontos(vector<Ponto*> pontos);
    void desenharPonto(Ponto ponto);
    void desenharLinha(float x1, float y1, float x2, float y2);
    void limpar();

private:
    MainWindow * _main_window;

    QGraphicsScene * _viewport;


public slots:

};

#endif // CANVAS_H
