#ifndef CONJUNTODEDADOS_H
#define CONJUNTODEDADOS_H

#include <vector>
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#include "ponto.h"

class ConjuntoDeDados
{
public:
    ConjuntoDeDados(int classes);
    ConjuntoDeDados(string nome_arquivo);

    int classes();
    const vector<Ponto*> pontos();
    int dimensoes();

protected:
    int _classes;
    vector<Ponto*> _pontos;
};

#endif // CONJUNTODEDADOS_H
