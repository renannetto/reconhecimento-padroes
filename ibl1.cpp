#include "ibl1.h"

IBL1::IBL1(Distancia * distancia) : IBL(distancia)
{
}

void IBL1::treinar(Ponto * ponto)
{
    list<pair<float, int> > distancias = calcularDistancias(ponto);

    int ymax = distancias.front().second;
    if (ymax==ponto->classe())
    {
        _corretas++;
    } else
    {
        _incorretas++;
    }

    _treino.push_back(ponto);
}
