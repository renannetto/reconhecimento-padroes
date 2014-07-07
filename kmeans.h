#ifndef KMEANS_H
#define KMEANS_H

#include <stdlib.h>
#include <limits>

#include "conjuntodedados.h"
#include "distribuicaof.h"
#include "distanciaeuclides.h"

class KMeans
{
public:
    KMeans(int k);
    ~KMeans();

    void agrupar(ConjuntoDeDados * dados);

    bool testeANOVA(ConjuntoDeDados * dados);

private:
    int _k;
    DistanciaEuclides _distancia;

    vector<Ponto> atualizarCentroides(vector<Ponto*> pontos);
    bool agruparPontos(vector<Ponto*> * pontos, vector<Ponto> centroides);
};

#endif // KMEANS_H
