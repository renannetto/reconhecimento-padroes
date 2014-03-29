#include "conjuntodedados.h"

ConjuntoDeDados::ConjuntoDeDados(int classes)
{
    _classes = classes;
}

int ConjuntoDeDados::classes()
{
    return _classes;
}

const vector<Ponto*> ConjuntoDeDados::pontos()
{
    return _pontos;
}
