#include "ibl2.h"

IBL2::IBL2(Distancia * distancia) : IBL(distancia)
{
}

void IBL2::treinar(Ponto *ponto)
{
    list<pair<float, int> > distancias = calcularDistancias(ponto);

    if (_treino.size() > 0)
    {
        int indice_max = distancias.front().second;
        int ymax = _treino.at(indice_max)->classe();
        if (ymax==ponto->classe())
        {
            _corretas++;
        } else
        {
            _incorretas++;
            _treino.push_back(ponto);
        }
    } else
    {
        _treino.push_back(ponto);
    }
}
