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
    if (_distancia <= corte)
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

float NodoDendograma::distanciaMaxima()
{
    if (!_ramo1 && !_ramo2)
    {
        return _distancia;
    }
    float ramos_maximo = max(_ramo1->distanciaMaxima(), _ramo2->distanciaMaxima());
    return max(ramos_maximo, _distancia);
}

void NodoDendograma::normalizar(float distancia_maxima)
{
    _distancia = _distancia / distancia_maxima;
    if (_ramo1)
    {
        _ramo1->normalizar(distancia_maxima);
    }
    if (_ramo2)
    {
        _ramo2->normalizar(distancia_maxima);
    }
}

void NodoDendograma::desenhar(Canvas * viewport, float posicao, float posicao_pai)
{
    if (_ramo1 && _ramo2)
    {        
        float x = _distancia*viewport->width()-5.0f;
        float x_ramo1 = _ramo1->_distancia*viewport->width();
        float x_ramo2 = _ramo2->_distancia*viewport->width();
        float largura = abs(posicao_pai - posicao);
        float y_ramo1 = posicao - (largura / 2.0f);
        float y_ramo2 = posicao + (largura / 2.0f);

        viewport->desenharLinha(x, posicao, x, y_ramo1);
        viewport->desenharLinha(x, y_ramo1, x_ramo1, y_ramo1);
        viewport->desenharLinha(x, posicao, x, y_ramo2);
        viewport->desenharLinha(x, y_ramo2, x_ramo2, y_ramo2);

        _ramo1->desenhar(viewport, y_ramo1, posicao);
        _ramo2->desenhar(viewport, y_ramo2, posicao);
    }
}

vector<Ponto*> NodoDendograma::pontos()
{
    return _instancias;
}
