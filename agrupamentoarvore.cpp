#include "agrupamentoarvore.h"

AgrupamentoArvore::AgrupamentoArvore(Distancia * distancia)
{
    _distancia = distancia;
}

AgrupamentoArvore::~AgrupamentoArvore()
{
}

void AgrupamentoArvore::agrupar(ConjuntoDeDados * dados)
{
    dados->estandardizar();
    vector<vector<float> > distancias;
    vector<Ponto*> pontos = dados->pontos();
    for (size_t indice_ponto1 = 0; indice_ponto1 < pontos.size(); indice_ponto1++)
    {
        Ponto * ponto1 = pontos.at(indice_ponto1);
        vector<float> distancias_ponto1;
        for (size_t indice_ponto2 = indice_ponto1+1; indice_ponto2 < pontos.size(); indice_ponto2++)
        {
            Ponto * ponto2 = pontos.at(indice_ponto2);
            distancias_ponto1.push_back(_distancia->distancia(ponto1, ponto2));
        }
        distancias.push_back(distancias_ponto1);
    }
}
