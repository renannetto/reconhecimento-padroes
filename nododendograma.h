#ifndef NODODENDOGRAMA_H
#define NODODENDOGRAMA_H

#include <vector>

#include "ponto.h"

using namespace std;

class NodoDendograma
{
public:
    NodoDendograma(vector<Ponto*> instancias, float distancia, NodoDendograma * ramo1, NodoDendograma * ramo2);

    vector<NodoDendograma*> obterCorte(vector<NodoDendograma*> nodos_corte, float corte);
    bool contem(Ponto * ponto);

    vector<Ponto*> pontos();

private:
    vector<Ponto*> _instancias;
    float _distancia;
    NodoDendograma * _ramo1;
    NodoDendograma * _ramo2;
};

#endif // NODODENDOGRAMA_H
