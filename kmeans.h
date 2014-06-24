#ifndef KMEANS_H
#define KMEANS_H

#include <stdlib.h>
#include <limits>

#include "distribuicaof.h"
#include "agrupador.h"
#include "distanciaeuclides.h"

class KMeans : public Agrupador
{
public:
    KMeans(int k);
    ~KMeans();

    void agrupar(ConjuntoDeDados * dados);

private:
    int _k;
    DistanciaEuclides _distancia;

    vector<Ponto> atualizarCentroides(vector<Ponto*> pontos);
    bool agruparPontos(vector<Ponto*> * pontos, vector<Ponto> centroides);

    bool testeF(ConjuntoDeDados * dados);
};

#endif // KMEANS_H
