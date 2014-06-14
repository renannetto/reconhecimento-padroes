#ifndef DISTANCIACOMPLETA_H
#define DISTANCIACOMPLETA_H

#include <limits>

#include "distanciacluster.h"

class DistanciaCompleta : public DistanciaCluster
{
public:
    DistanciaCompleta(Distancia * distancia);

    float distancia(vector<Ponto *> cluster1, vector<Ponto *> cluster2);
};

#endif // DISTANCIACOMPLETA_H
