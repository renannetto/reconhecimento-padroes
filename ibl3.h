#ifndef IBL3_H
#define IBL3_H

#include <stdlib.h>

#include "ibl.h"

class IBL3 : public IBL
{
public:
    IBL3(Distancia * distancia);

    void treinar(Ponto *ponto);

private:
    vector<pair<float> > _intervalo_frequencia;
    float _aceitabilidade;
    float _descarte;
    vector<int> _contador_classes;
};

#endif // IBL3_H
