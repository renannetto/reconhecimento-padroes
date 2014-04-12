#include "ibl4.h"

IBL4::IBL4(Distancia * distancia, int classes, float aceitabilidade, float descarte) :
    IBL3(distancia, classes, aceitabilidade, descarte)
{
}

float IBL4::calcularDistancia(Ponto *ponto1, Ponto *ponto2)
{
    return _distancia->distancia(ponto1, ponto2, _pesos);
}
