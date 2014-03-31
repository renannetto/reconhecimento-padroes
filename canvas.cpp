#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QGraphicsView(parent)
{

}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    _main_window->mousePressEvent(event);
}

void Canvas::fixarMainWindow(MainWindow * main_window)
{
    _main_window = main_window;
}
