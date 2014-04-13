#include "ponto.h"

Ponto::Ponto()
{
    _classe = -1;
    _contador = 0;
    _corretas = 0;
}

Ponto::Ponto(vector<float> atributos, int classe)
{
    _atributos = atributos;
    _classe = classe;
    _contador = 0;
    _corretas = 0;
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

void Ponto::usada()
{
    _contador++;
}

void Ponto::correta()
{
    _corretas++;
}

int Ponto::contador()
{
    return _contador;
}

int Ponto::corretas()
{
    return _corretas;
}

bool Ponto::ambosConhecidos(Ponto *ponto2, int dimensao)
{
    return true;
}
