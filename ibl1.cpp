#include "ibl1.h"

IBL1::IBL1(Distancia * distancia) : IBL(distancia)
{
}

Ponto * IBL1::treinar(Ponto * ponto)
{
    list<pair<float, int> > distancias = calcularDistancias(ponto);

    if (_treino.size()>0)
    {
        int indice_max = distancias.front().second;
        int ymax = _treino.at(indice_max)->classe();
        if (ymax==ponto->classe())
        {
            _corretas++;
        } else
        {
            _incorretas++;
        }
        _treino.push_back(ponto);

        return _treino.at(indice_max);
    }

    _incorretas++;
    _treino.push_back(ponto);
    return 0;
}
