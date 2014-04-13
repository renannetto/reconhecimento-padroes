#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QGraphicsView(parent)
{
    _viewport = new QGraphicsScene(-320, -240, 640, 480, this);
    setScene(_viewport);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    QPointF ponto = mapToScene(QPoint(event->x(), event->y()));
    _main_window->mousePressEvent(ponto.x(), ponto.y());
}

void Canvas::fixarMainWindow(MainWindow * main_window)
{
    _main_window = main_window;
}

void Canvas::desenharPonto(Ponto ponto)
{
    int classe = ponto.classe();
    QColor cor = PaletaDeCores::cores.at(classe);

    _viewport->addEllipse(ponto.x()-2.5f, ponto.y()-2.5f, 5.0f, 5.0f, QPen(cor), QBrush(cor));
}

void Canvas::limpar()
{
    _viewport->clear();
}
