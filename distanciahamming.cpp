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

float DistanciaHamming::distancia(Ponto *ponto1, Ponto *ponto2, vector<float> pesos, bool ausentes)
{
    assert(ponto1->dimensoes()==ponto2->dimensoes());

    float distancia = 0;
    for (int dimensao = 0; dimensao < ponto1->dimensoes(); dimensao++)
    {
        if (!ausentes || ponto1->ambosConhecidos(ponto2, dimensao))
        {
            distancia += abs(ponto1->at(dimensao)-ponto2->at(dimensao))*pesos.at(dimensao)*pesos.at(dimensao);
        }
    }
    return distancia;
}
