#ifndef DISTANCIAMEDIA_H
#define DISTANCIAMEDIA_H

#include "distanciacluster.h"

class DistanciaMedia : public DistanciaCluster
{
public:
    DistanciaMedia(Distancia * distancia);

    float distancia(vector<Ponto *> cluster1, vector<Ponto *> cluster2);
};

#endif // DISTANCIAMEDIA_H
