#ifndef CONJUNTODEDADOS_H
#define CONJUNTODEDADOS_H

#include <vector>
#include <math.h>

using namespace std;

#include "ponto.h"

class ConjuntoDeDados
{
public:
    ConjuntoDeDados(int classes);

    int classes();
    const vector<Ponto*> pontos();

protected:
    int _classes;
    vector<Ponto*> _pontos;
};

#endif // CONJUNTODEDADOS_H
