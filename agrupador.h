#ifndef AGRUPADOR_H
#define AGRUPADOR_H

#include "conjuntodedados.h"

class Agrupador
{
public:
    Agrupador();
    virtual ~Agrupador();

    virtual void agrupar(ConjuntoDeDados * dados) = 0;
};

#endif // AGRUPADOR_H
