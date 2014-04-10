#include "nearestneighbor.h"

NearestNeighbor::NearestNeighbor(Distancia * distancia, ConjuntoDeDados * dados, int vizinhos) : Classificador(distancia)
{
    _dados = dados;
    _vizinhos = vizinhos;
}

int NearestNeighbor::classificar(Ponto * ponto)
{
    vector<Ponto*> pontos = _dados->pontos();
    int classes = _dados->classes();

    list<pair<float, int> > custos;
    custos.resize(_vizinhos, pair<float, int>(numeric_limits<float>::max(), -1));

    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        float dist = _distancia->distancia(ponto, pontos.at(indice_ponto));
        list<pair<float, int> >::iterator iterador_custos;
        list<pair<float, int> >::iterator end = custos.end();
        for (iterador_custos = custos.begin(); iterador_custos != end; iterador_custos++)
        {
            if (dist < iterador_custos->first)
            {
                custos.insert(iterador_custos, pair<float, int>(dist, pontos.at(indice_ponto)->classe()));
                break;
            }
        }
        custos.resize(_vizinhos);
    }

    vector<int> votos;
    votos.resize(classes);
    list<pair<float, int> >::iterator iterador_custos;
    for (iterador_custos = custos.begin(); iterador_custos != custos.end(); iterador_custos++)
    {
        int classe = iterador_custos->second;
        votos.at(classe) += 1;
    }

    int max_votos = votos.at(0);
    int melhor_classe = 0;
    for (int classe = 1; classe < classes; classe++)
    {
        if (votos.at(classe) > max_votos)
        {
            max_votos = votos.at(classe);
            melhor_classe = classe;
        }
    }

    return melhor_classe;
}
