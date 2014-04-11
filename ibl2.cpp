#include "ibl2.h"

IBL2::IBL2(Distancia * distancia) : IBL(distancia)
{
}

void IBL2::treinar(Ponto *ponto)
{
    list<pair<float, int> > distancias = calcularDistancias(ponto);

    int ymax = distancias.front().second;
    if (ymax==ponto->classe())
    {
        _corretas++;
    } else
    {
        _incorretas++;
        _treino.push_back(ponto);
    }
}
