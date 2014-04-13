#include "ibl4.h"

IBL4::IBL4(Distancia * distancia, int classes, int dimensoes, float aceitabilidade, float descarte) :
    IBL3(distancia, classes, aceitabilidade, descarte)
{
    _pesos.resize(dimensoes, 1);
    _pesos_acumulados.resize(dimensoes, 1);
    _pesos_normalizados.resize(dimensoes, 1);
}

float IBL4::calcularDistancia(Ponto *ponto1, Ponto *ponto2)
{
    return _distancia->distancia(ponto1, ponto2, _pesos);
}

void IBL4::atualizarPeso(Ponto* ponto_max, int dimensao, Ponto *ponto)
{
    float diferenca = abs(ponto->at(dimensao)-ponto_max->at(dimensao));
    float frequencia_classe1 = (float)_contador_classes.at(ponto->classe()) / _observados;
    float frequencia_classe2 = (float)_contador_classes.at(ponto_max->classe()) / _observados;
    float lambda = max(frequencia_classe1, frequencia_classe2);
    if (ponto->classe() == ponto_max->classe())
    {
        _pesos_acumulados.at(dimensao) += (1-lambda) * (1-diferenca);
    } else
    {
        _pesos_acumulados.at(dimensao) += (1-lambda) * diferenca;
    }

    _pesos_normalizados.at(dimensao) += 1-lambda;
    _pesos.at(dimensao) = max(_pesos_acumulados.at(dimensao)/_pesos_normalizados.at(dimensao) - 0.5f, 0.0f);
}

Ponto * IBL4::treinar(Ponto *ponto)
{
    Ponto * ponto_max = IBL3::treinar(ponto);
    if (_treino.size() > 1)
    {
        for (int dimensao = 0; dimensao < ponto->dimensoes(); dimensao++)
        {
            atualizarPeso(ponto_max, dimensao, ponto);
        }
    }

    return ponto_max;
}
