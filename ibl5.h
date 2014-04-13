#ifndef IBL5_H
#define IBL5_H

#include "ibl4.h"

class IBL5 : public IBL4
{
public:
    IBL5(Distancia * distancia, int classes, int dimensoes, float aceitabilidade = 0.9, float descarte = 0.75);

    Ponto * treinar(Ponto *ponto);
};

#endif // IBL5_H
