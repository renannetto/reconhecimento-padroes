#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QGraphicsView(parent)
{
    _viewport = new QGraphicsScene(this);
    setScene(_viewport);
}

void Canvas::fixarMainWindow(MainWindow * main_window)
{
    _main_window = main_window;
}

void Canvas::desenharPontos(vector<Ponto *> pontos)
{
    limpar();
    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        desenharPonto(*pontos.at(indice_ponto));
    }
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
