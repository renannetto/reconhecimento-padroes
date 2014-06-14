#ifndef AGRUPAMENTOARVORE_H
#define AGRUPAMENTOARVORE_H

#include "agrupador.h"
#include "distancia.h"

class AgrupamentoArvore : public Agrupador
{
public:
    AgrupamentoArvore(Distancia * distancia);
    ~AgrupamentoArvore();

    void agrupar(ConjuntoDeDados * dados);

private:
    Distancia * _distancia;
};

#endif // AGRUPAMENTOARVORE_H
