#ifndef NEARESTNEIGHBOR_H
#define NEARESTNEIGHBOR_H

#include <list>
#include <limits>

#include "classificador.h"
#include "conjuntodedados.h"

class NearestNeighbor : public Classificador
{
public:
    NearestNeighbor(Distancia * distancia, ConjuntoDeDados * dados, int vizinhos);

    int classificar(Ponto * ponto);

private:
    ConjuntoDeDados * _dados;
    int _vizinhos;
};

#endif // NEARESTNEIGHBOR_H
