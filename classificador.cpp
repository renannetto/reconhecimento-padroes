#include "classificador.h"

Classificador::Classificador(Distancia * distancia)
{
    _distancia = distancia;
}

Classificador::~Classificador()
{
    delete _distancia;
}
