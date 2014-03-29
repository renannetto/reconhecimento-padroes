#include "ponto.h"

Ponto::Ponto(vector<float> coordenadas, int classe)
{
    _coordenadas = coordenadas;
    _classe = classe;
}

int Ponto::dimensoes()
{
    return _coordenadas.size();
}

int Ponto::classe()
{
    return _classe;
}

float Ponto::at(int dimensao)
{
    return _coordenadas.at(dimensao);
}

float Ponto::x()
{
    return _coordenadas.at(0);
}

float Ponto::y()
{
    return _coordenadas.at(1);
}
