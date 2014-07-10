#ifndef KMEANS_H
#define KMEANS_H

#include <stdlib.h>
#include <limits>

#include "conjuntodedados.h"
#include "distribuicaof.h"
#include "distanciaeuclides.h"
#include "anova.h"

class KMeans
{
public:
    KMeans(ConjuntoDeDados * dados, int k);
    ~KMeans();

    void agrupar();

    anova testeANOVA();
    void exportar(string nome_arquivo);

private:
    ConjuntoDeDados * _dados;
    int _k;
    DistanciaEuclides _distancia;

    vector<Ponto> atualizarCentroides(vector<Ponto*> pontos);
    bool agruparPontos(vector<Ponto*> * pontos, vector<Ponto> centroides);
};

#endif // KMEANS_H
