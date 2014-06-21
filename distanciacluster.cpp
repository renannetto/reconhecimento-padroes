#include "distanciacluster.h"

DistanciaCluster::DistanciaCluster(Distancia * distancia)
{
    _distancia = distancia;
}

float DistanciaCluster::distancia(Ponto *ponto, vector<Ponto *> cluster)
{
    vector<Ponto*> cluster_ponto;
    cluster_ponto.push_back(ponto);
    return this->distancia(cluster_ponto, cluster);
}
