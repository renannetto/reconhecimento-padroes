#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>
#include <iostream>
#include "mainwindow.h"
#include <QWheelEvent>

using namespace std;

class MainWindow;
class Canvas : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = 0);
    void fixarMainWindow(MainWindow * main_window);

private:
    MainWindow * _main_window;

protected:
    virtual void mousePressEvent(QMouseEvent *event);


public slots:

};

#endif // CANVAS_H
