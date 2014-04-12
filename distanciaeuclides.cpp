#include "distanciaeuclides.h"

DistanciaEuclides::DistanciaEuclides()
{
}

float DistanciaEuclides::distancia(Ponto *ponto1, Ponto *ponto2)
{
    assert(ponto1->dimensoes()==ponto2->dimensoes());

    float distancia = 0;
    for (int dimensao = 0; dimensao < ponto1->dimensoes(); dimensao++)
    {
        float diferenca = ponto1->at(dimensao)-ponto2->at(dimensao);
        distancia += diferenca*diferenca;
    }
    return sqrt(distancia);
}

float DistanciaEuclides::distancia(Ponto *ponto1, Ponto *ponto2, vector<float> pesos)
{
    assert(ponto1->dimensoes()==ponto2->dimensoes());

    float distancia = 0;
    for (int dimensao = 0; dimensao < ponto1->dimensoes(); dimensao++)
    {
        float diferenca = ponto1->at(dimensao)-ponto2->at(dimensao);
        distancia += diferenca*diferenca*pesos.at(dimensao)*pesos.at(dimensao);
    }
    return sqrt(distancia);
}
