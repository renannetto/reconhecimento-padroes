#ifndef IBL_H
#define IBL_H

#include <list>
#include <limits>

#include "classificador.h"
#include "conjuntodedados.h"

class IBL : public Classificador
{
public:
    IBL(Distancia * distancia);

    void treinar(ConjuntoDeDados * dados);
    virtual Ponto * treinar(Ponto * ponto) = 0;
    list<pair<float, int> > calcularDistancias(Ponto * ponto);
    virtual float calcularDistancia(Ponto * ponto1, Ponto * ponto2);
    int classificar(Ponto *ponto);

    const vector<Ponto*> treino();
    int corretas();
    int incorretas();

protected:
    vector<Ponto*> _treino;

    int _corretas;
    int _incorretas;
};

#endif // IBL_H
