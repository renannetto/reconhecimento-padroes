#ifndef DISTANCIAEUCLIDES_H
#define DISTANCIAEUCLIDES_H

#include <iostream>

#include "distancia.h"

class DistanciaEuclides : public Distancia
{
public:
    DistanciaEuclides();

    float distancia(Ponto *ponto1, Ponto *ponto2);
    float distancia(Ponto *ponto1, Ponto *ponto2, vector<float> pesos, bool ausentes = false);
};

#endif // DISTANCIAEUCLIDES_H
