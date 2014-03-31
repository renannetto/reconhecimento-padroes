#ifndef ESPIRALSIMPLES_H
#define ESPIRALSIMPLES_H

#include <stdlib.h>

#include "conjuntodedados.h"

class EspiralSimples : public ConjuntoDeDados
{
public:
    EspiralSimples(int numero_pontos, float a, float b, float passo, int ruido);
};

#endif // ESPIRALSIMPLES_H
