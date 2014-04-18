#ifndef IBL4_H
#define IBL4_H

#include <cmath>

#include "ibl3.h"

#include <iostream>

class IBL4 : public IBL3
{
public:
    IBL4(Distancia * distancia, int classes, int dimensoes, float aceitabilidade = 0.9, float descarte = 0.75);

    Ponto * treinar(Ponto *ponto);
    float calcularDistancia(Ponto *ponto1, Ponto *ponto2);

    virtual void atualizarPeso(Ponto* ponto_max, int dimensao, Ponto *ponto);
private:
    vector<float> _pesos_acumulados;
    vector<float> _pesos_normalizados;
    vector<float> _pesos;
};

#endif // IBL4_H
