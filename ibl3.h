#ifndef IBL3_H
#define IBL3_H

#include <stdlib.h>

#include "ibl.h"

class IBL3 : public IBL
{
public:
    IBL3(Distancia * distancia, int classes, float aceitabilidade = 0.9, float descarte = 0.75);

    Ponto * treinar(Ponto *ponto);
    bool aceitavel(int indice_ponto, int classe);
    bool descartavel(int indice_ponto, int classe);
    pair<float, float> intervalo(float p, float n, float z);

protected:
    float _aceitabilidade;
    float _descarte;
    vector<int> _contador_classes;
    int _observados;
};

#endif // IBL3_H
