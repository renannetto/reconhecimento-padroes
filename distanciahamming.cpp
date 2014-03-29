#include "distanciahamming.h"

DistanciaHamming::DistanciaHamming()
{
}

float DistanciaHamming::distancia(Ponto *ponto1, Ponto *ponto2)
{
    assert(ponto1->dimensoes()==ponto2->dimensoes());

    float distancia = 0;
    for (int dimensao = 0; dimensao < ponto1->dimensoes(); dimensao++)
    {
        distancia += abs(ponto1->at(dimensao)-ponto2->at(dimensao));
    }
    return distancia;
}
