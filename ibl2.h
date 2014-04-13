#ifndef IBL2_H
#define IBL2_H

#include "ibl.h"

class IBL2 : public IBL
{
public:
    IBL2(Distancia * distancia);

    Ponto * treinar(Ponto *ponto);
};

#endif // IBL2_H
