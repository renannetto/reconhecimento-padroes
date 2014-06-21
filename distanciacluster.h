#ifndef DISTANCIACLUSTER_H
#define DISTANCIACLUSTER_H

#include "distancia.h"

class DistanciaCluster
{
public:
    DistanciaCluster(Distancia * distancia);

    virtual float distancia(vector<Ponto*> cluster1, vector<Ponto*> cluster2) = 0;
    float distancia(Ponto * ponto, vector<Ponto*> cluster);

protected:
    Distancia * _distancia;
};

#endif // DISTANCIACLUSTER_H
