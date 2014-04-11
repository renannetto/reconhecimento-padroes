#ifndef IBL1_H
#define IBL1_H

#include "ibl.h"

#include <list>

class IBL1 : public IBL
{
public:
    IBL1(Distancia * distancia);

    void treinar(Ponto * ponto);
};

#endif // IBL1_H
