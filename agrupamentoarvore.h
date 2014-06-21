#ifndef AGRUPAMENTOARVORE_H
#define AGRUPAMENTOARVORE_H

#include <limits>
#include <set>

#include "agrupador.h"
#include "distanciacluster.h"

class AgrupamentoArvore : public Agrupador
{
public:
    AgrupamentoArvore(DistanciaCluster * distancia, int min_class, int max_class, float plato);
    ~AgrupamentoArvore();

    void agrupar(ConjuntoDeDados * dados);

private:
    DistanciaCluster * _distancia;
    int _min_class;
    int _max_class;
    float _plato;
};

#endif // AGRUPAMENTOARVORE_H
