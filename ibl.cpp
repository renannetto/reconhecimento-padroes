#include "ibl.h"

IBL::IBL(Distancia * distancia) : Classificador(distancia)
{
    _corretas = 0;
    _incorretas = 0;
}

void IBL::treinar(ConjuntoDeDados *dados)
{
    vector<Ponto*> pontos = dados->pontos();
    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        Ponto * ponto = pontos.at(indice_ponto);
        treinar(ponto);
    }
}

list<pair<float, int> > IBL::calcularDistancias(Ponto *ponto)
{
    list<pair<float, int> > distancias;
    distancias.push_back(pair<float, int>(numeric_limits<float>::max(), -1));
    for (size_t indice_treino = 0; indice_treino < _treino.size(); indice_treino++)
    {
        Ponto * ponto_treino = _treino.at(indice_treino);
        float distancia = calcularDistancia(ponto, ponto_treino);

        list<pair<float, int> >::iterator iterador_distancias;
        list<pair<float, int> >::iterator end = distancias.end();
        for (iterador_distancias = distancias.begin(); iterador_distancias != end; iterador_distancias++)
        {
            if (distancia < iterador_distancias->first)
            {
                distancias.insert(iterador_distancias, pair<float, int>(distancia, indice_treino));
                break;
            }
        }
    }
    distancias.pop_back();
    return distancias;
}

float IBL::calcularDistancia(Ponto *ponto1, Ponto *ponto2)
{
    return _distancia->distancia(ponto1, ponto2);
}

int IBL::classificar(Ponto *ponto)
{
    list<pair<float, int> > distancias = calcularDistancias(ponto);

    Ponto * melhor_ponto = _treino.at(distancias.front().second);
    return melhor_ponto->classe();
}

const vector<Ponto*> IBL::treino()
{
    return _treino;
}

int IBL::corretas()
{
    return _corretas;
}

int IBL::incorretas()
{
    return _incorretas;
}
