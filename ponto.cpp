#include "ponto.h"

Ponto::Ponto(vector<float> coordenadas)
{
    _coordenadas = coordenadas;
}

int Ponto::dimensoes()
{
    return _coordenadas.size();
}

const vector<float> Ponto::coordenadas()
{
    return _coordenadas;
}

float Ponto::x()
{
    return _coordenadas.at(0);
}

float Ponto::y()
{
    return _coordenadas.at(1);
}
