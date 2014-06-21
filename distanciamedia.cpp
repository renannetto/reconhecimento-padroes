#include "distanciamedia.h"

DistanciaMedia::DistanciaMedia(Distancia * distancia) : DistanciaCluster(distancia)
{
}

float DistanciaMedia::distancia(vector<Ponto *> cluster1, vector<Ponto *> cluster2)
{
    float distancia_media = 0;
    for (size_t indice_ponto1 = 0; indice_ponto1 < cluster1.size(); indice_ponto1++)
    {
        Ponto * ponto1 = cluster1.at(indice_ponto1);
        for (size_t indice_ponto2 = 0; indice_ponto2 < cluster2.size(); indice_ponto2++)
        {
            Ponto * ponto2 = cluster2.at(indice_ponto2);
            distancia_media += _distancia->distancia(ponto1, ponto2);

        }
    }
    return distancia_media / (cluster1.size()*cluster2.size());
}
