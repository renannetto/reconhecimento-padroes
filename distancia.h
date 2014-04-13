#ifndef DISTANCIA_H
#define DISTANCIA_H

#include <assert.h>
#include <stdlib.h>
#include <math.h>

#include "ponto.h"

class Distancia
{
public:
    Distancia();
    virtual ~Distancia();

    virtual float distancia(Ponto * ponto1, Ponto * ponto2) = 0;
    virtual float distancia(Ponto *ponto1, Ponto *ponto2, vector<float> pesos, bool ausentes = false) = 0;
};

#endif // DISTANCIA_H
