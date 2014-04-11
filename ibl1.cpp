#include "ibl1.h"

IBL1::IBL1(Distancia * distancia) : IBL(distancia)
{
}

void IBL1::treinar(Ponto * ponto)
{
    list<pair<float, int> > distancias = calcularDistancias(ponto);

    int indice_max = distancias.front().second;
    int ymax = (indice_max == -1) ? -1 : _treino.at(indice_max)->classe();
    if (ymax==ponto->classe())
    {
        _corretas++;
    } else
    {
        _incorretas++;
    }

    _treino.push_back(ponto);
}
