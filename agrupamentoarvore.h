#ifndef AGRUPAMENTOARVORE_H
#define AGRUPAMENTOARVORE_H

#include <limits>
#include <set>

#include "nododendograma.h"
#include "conjuntodedados.h"
#include "distanciacluster.h"

class AgrupamentoArvore
{
public:
    AgrupamentoArvore(ConjuntoDeDados * dados, DistanciaCluster * distancia);
    ~AgrupamentoArvore();

    void agrupar();
    void exportarClassificacao(string nome_arquivo, float corte);

private:
    ConjuntoDeDados * _dados;
    DistanciaCluster * _distancia;
    NodoDendograma * _raiz;
};

#endif // AGRUPAMENTOARVORE_H
