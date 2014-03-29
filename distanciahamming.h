#ifndef DISTANCIAHAMMING_H
#define DISTANCIAHAMMING_H

#include "distancia.h"

class DistanciaHamming : public Distancia
{
public:
    DistanciaHamming();

    float distancia(Ponto *ponto1, Ponto *ponto2);
};

#endif // DISTANCIAHAMMING_H
