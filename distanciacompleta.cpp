#include "distanciacompleta.h"

DistanciaCompleta::DistanciaCompleta(Distancia * distancia) : DistanciaCluster(distancia)
{
}

float DistanciaCompleta::distancia(vector<Ponto *> cluster1, vector<Ponto *> cluster2)
{
    float distancia_maxima = std::numeric_limits<float>::min();
    for (size_t indice_ponto1 = 0; indice_ponto1 < cluster1.size(); indice_ponto1++)
    {
        Ponto * ponto1 = cluster1.at(indice_ponto1);
        for (size_t indice_ponto2 = 0; indice_ponto2 < cluster2.size(); indice_ponto2++)
        {
            Ponto * ponto2 = cluster2.at(indice_ponto2);
            float distancia = _distancia->distancia(ponto1, ponto2);
            if (distancia > distancia_maxima)
            {
                distancia_maxima = distancia;
            }
        }
    }
    return distancia_maxima;
}
