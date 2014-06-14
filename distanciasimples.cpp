#include "distanciasimples.h"

DistanciaSimples::DistanciaSimples(Distancia * distancia) : DistanciaCluster(distancia)
{
}

float DistanciaSimples::distancia(vector<Ponto *> cluster1, vector<Ponto *> cluster2)
{
    float distancia_minima = std::numeric_limits<float>::max();
    for (size_t indice_ponto1 = 0; indice_ponto1 < cluster1.size(); indice_ponto1++)
    {
        Ponto * ponto1 = cluster1.at(indice_ponto1);
        for (size_t indice_ponto2 = 0; indice_ponto2 < cluster2.size(); indice_ponto2++)
        {
            Ponto * ponto2 = cluster2.at(indice_ponto2);
            float distancia = _distancia->distancia(ponto1, ponto2);
            if (distancia < distancia_minima)
            {
                distancia_minima = distancia;
            }
        }
    }
    return distancia_minima;
}
