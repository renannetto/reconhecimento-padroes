#include "nododendograma.h"

NodoDendograma::NodoDendograma(vector<Ponto*> instancias, float distancia, NodoDendograma * ramo1, NodoDendograma * ramo2)
{
    _instancias = instancias;
    _distancia = distancia;
    _ramo1 = ramo1;
    _ramo2 = ramo2;
}

vector<NodoDendograma*> NodoDendograma::obterCorte(vector<NodoDendograma*> nodos_corte, float corte)
{
    if (_distancia < corte)
    {
        nodos_corte.push_back(this);
        return nodos_corte;
    }

    nodos_corte = _ramo1->obterCorte(nodos_corte, corte);
    nodos_corte = _ramo2->obterCorte(nodos_corte, corte);
    return nodos_corte;
}

bool NodoDendograma::contem(Ponto *ponto)
{
    for (size_t indice_ponto = 0; indice_ponto < _instancias.size(); indice_ponto++)
    {
        if (ponto == _instancias.at(indice_ponto))
        {
            return true;
        }
    }
    return false;
}

vector<Ponto*> NodoDendograma::pontos()
{
    return _instancias;
}
