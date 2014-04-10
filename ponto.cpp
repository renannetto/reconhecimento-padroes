#include "ponto.h"

Ponto::Ponto()
{
    _classe = -1;
}

Ponto::Ponto(vector<float> atributos, int classe)
{
    _atributos = atributos;
    _classe = classe;
}

int Ponto::dimensoes()
{
    return _atributos.size();
}

int Ponto::classe()
{
    return _classe;
}

float Ponto::at(int dimensao)
{
    return _atributos.at(dimensao);
}

void Ponto::at(int dimensao, float atributo)
{
    _atributos.at(dimensao) = atributo;
}

float Ponto::x()
{
    return _atributos.at(0);
}

float Ponto::y()
{
    return _atributos.at(1);
}
