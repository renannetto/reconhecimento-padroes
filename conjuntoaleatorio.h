#ifndef CONJUNTOALEATORIO_H
#define CONJUNTOALEATORIO_H

#include <stdlib.h>

#include <iostream>
using namespace std;

#include "conjuntodedados.h"

class ConjuntoAleatorio : public ConjuntoDeDados
{
public:
    ConjuntoAleatorio(int classes, int numero_pontos, int min_x, int min_y, int max_x, int max_y);
};

#endif // CONJUNTOALEATORIO_H
