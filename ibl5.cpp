#include "ibl5.h"

IBL5::IBL5(Distancia * distancia, int classes, int dimensoes, float aceitabilidade, float descarte) :
    IBL4(distancia, classes, dimensoes, aceitabilidade, descarte)
{
}

Ponto * IBL5::treinar(Ponto *ponto)
{
    Ponto * ponto_max = IBL3::treinar(ponto);
    if (_treino.size() > 1)
    {
        for (int dimensao = 0; dimensao < ponto->dimensoes(); dimensao++)
        {
            if (ponto->ambosConhecidos(ponto_max, dimensao))
            {
                atualizarPeso(ponto_max, dimensao, ponto);
            }
        }
    }

    return ponto_max;
}
