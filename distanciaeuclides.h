#ifndef DISTANCIAEUCLIDES_H
#define DISTANCIAEUCLIDES_H

#include "distancia.h"

class DistanciaEuclides : public Distancia
{
public:
    DistanciaEuclides();

    float distancia(Ponto *ponto1, Ponto *ponto2);
};

#endif // DISTANCIAEUCLIDES_H
