#ifndef AGRUPADOR_H
#define AGRUPADOR_H

#include "conjuntodedados.h"

class Agrupador
{
public:
    Agrupador();
    virtual ~Agrupador();

    virtual void agrupar(ConjuntoDeDados * dados) = 0;

    virtual bool testeF(ConjuntoDeDados * dados);
};

#endif // AGRUPADOR_H
