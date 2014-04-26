#ifndef CONJUNTODEDADOS_H
#define CONJUNTODEDADOS_H

#include <vector>
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

#include "ponto.h"

class ConjuntoDeDados
{
public:
    ConjuntoDeDados(int classes);
    ConjuntoDeDados(string nome_arquivo);

    void normalizar();
    void normalizarPonto(Ponto * ponto);
    void adicionarRuido(int incidencia, int ruido);
    void removerAtributos(int probabilidade);

    int classes();
    const vector<Ponto*> pontos();
    int dimensoes();

protected:
    int _classes;
    vector<Ponto*> _pontos;
    Ponto _ponto_max;
    Ponto _ponto_min;
};

#endif // CONJUNTODEDADOS_H
