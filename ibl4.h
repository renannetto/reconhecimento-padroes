#ifndef IBL4_H
#define IBL4_H

#include "ibl3.h"

class IBL4 : public IBL3
{
public:
    IBL4(Distancia * distancia, int classes, float aceitabilidade = 0.9, float descarte = 0.75);

    float calcularDistancia(Ponto *ponto1, Ponto *ponto2);

private:
    vector<float> _pesos;
};

#endif // IBL4_H
