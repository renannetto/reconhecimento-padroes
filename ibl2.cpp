#include "ibl2.h"

IBL2::IBL2(Distancia * distancia) : IBL(distancia)
{
}

void IBL2::treinar(Ponto *ponto)
{
    list<pair<float, int> > distancias = calcularDistancias(ponto);

    Ponto * ponto_max = _treino.at(distancias.front().second);
    int ymax = ponto_max->classe();
    if (ymax==ponto->classe())
    {
        _corretas++;
    } else
    {
        _incorretas++;
        _treino.push_back(ponto);
    }
}
