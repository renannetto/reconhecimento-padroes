#ifndef DISTANCIASIMPLES_H
#define DISTANCIASIMPLES_H

#include <limits>

#include "distanciacluster.h"

class DistanciaSimples : DistanciaCluster
{
public:
    DistanciaSimples(Distancia * distancia);

    float distancia(vector<Ponto *> cluster1, vector<Ponto *> cluster2);
};

#endif // DISTANCIASIMPLES_H
