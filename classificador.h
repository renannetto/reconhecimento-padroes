#ifndef CLASSIFICADOR_H
#define CLASSIFICADOR_H

#include "distancia.h"

class Classificador
{
friend class NearestNeighbor;

public:
    Classificador(Distancia * distancia);
    virtual ~Classificador();

    virtual int classificar(Ponto * ponto) = 0;

protected:
    Distancia * _distancia;
};

#endif // CLASSIFICADOR_H
