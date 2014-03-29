#include "nearestneighbor.h"

NearestNeighbor::NearestNeighbor(vector<Ponto*> pontos, int classes)
{
    _pontos = pontos;
    _classes = classes;
}

int NearestNeighbor::classificar(Ponto *ponto, Distancia * distancia, int vizinhos)
{
    list<pair<float, int> > custos;
    custos.resize(vizinhos, pair<float, int>(numeric_limits<float>::max(), -1));

    for (size_t indice_ponto = 0; indice_ponto < _pontos.size(); indice_ponto++)
    {
        float dist = distancia->distancia(ponto, _pontos.at(indice_ponto));
        list<pair<float, int> >::iterator iterador_custos;
        list<pair<float, int> >::iterator end = custos.end();
        for (iterador_custos = custos.begin(); iterador_custos != end; iterador_custos++)
        {
            if (dist < iterador_custos->first)
            {
                custos.insert(iterador_custos, pair<float, int>(dist, _pontos.at(indice_ponto)->classe()));
            }
        }
        custos.resize(vizinhos);
    }

    vector<int> votos;
    votos.resize(_classes);
    list<pair<float, int> >::iterator iterador_custos;
    for (iterador_custos = custos.begin(); iterador_custos != custos.end(); iterador_custos++)
    {
        int classe = iterador_custos->second;
        votos.at(classe) += 1;
    }

    int max_votos = votos.at(0);
    int melhor_classe = 0;
    for (int classe = 1; classe < _classes; classe++)
    {
        if (votos.at(classe) > max_votos)
        {
            max_votos = votos.at(classe);
            melhor_classe = classe;
        }
    }

    return melhor_classe;
}
