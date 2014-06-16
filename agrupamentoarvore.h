#ifndef AGRUPAMENTOARVORE_H
#define AGRUPAMENTOARVORE_H

#include <limits>
#include <set>

#include "agrupador.h"
#include "distanciacluster.h"

class AgrupamentoArvore : public Agrupador
{
public:
    AgrupamentoArvore(DistanciaCluster * distancia);
    ~AgrupamentoArvore();

    void agrupar(ConjuntoDeDados * dados);

private:
    DistanciaCluster * _distancia;
};

#endif // AGRUPAMENTOARVORE_H
