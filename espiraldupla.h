#ifndef ESPIRALDUPLA_H
#define ESPIRALDUPLA_H

#include <stdlib.h>

#include "conjuntodedados.h"

class EspiralDupla : public ConjuntoDeDados
{
public:
    EspiralDupla(int numero_pontos, float a, float b, float passo, int ruido);
};

#endif // ESPIRALDUPLA_H
