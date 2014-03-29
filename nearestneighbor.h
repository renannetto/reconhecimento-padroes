#ifndef NEARESTNEIGHBOR_H
#define NEARESTNEIGHBOR_H

#include <list>
#include <limits>

#include "ponto.h"
#include "distancia.h"

class NearestNeighbor
{
public:
    NearestNeighbor(vector<Ponto*> pontos, int classes);

    int classificar(Ponto *ponto, Distancia * distancia, int vizinhos);

private:
    vector<Ponto*> _pontos;
    int _classes;
};

#endif // NEARESTNEIGHBOR_H
