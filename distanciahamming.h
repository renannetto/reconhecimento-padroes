#ifndef DISTANCIAHAMMING_H
#define DISTANCIAHAMMING_H

#include "distancia.h"

class DistanciaHamming : public Distancia
{
public:
    DistanciaHamming();

    float distancia(Ponto *ponto1, Ponto *ponto2);
    float distancia(Ponto *ponto1, Ponto *ponto2, vector<float> pesos);
};

#endif // DISTANCIAHAMMING_H
