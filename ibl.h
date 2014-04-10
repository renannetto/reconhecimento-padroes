#ifndef IBL_H
#define IBL_H

#include "classificador.h"

class IBL : public Classificador
{
public:
    IBL(Distancia * distancia);

    void treinar(Ponto * ponto);
};

#endif // IBL_H
