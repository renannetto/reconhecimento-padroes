#include "ibl3.h"

IBL3::IBL3(Distancia * distancia) : IBL(distancia)
{
}

void IBL3::treinar(Ponto *ponto)
{
    list<pair<float, int> > distancias = calcularDistancias(ponto);

    float menor_distancia;
    int ymax = -1;
    if (_treino.size()==0)
    {
        int indice_max = -1;
        list<pair<float, int> >::iterator iterador_distancias;
        list<pair<float, int> >::iterator end = distancias.end();
        for (iterador_distancias = distancias.begin(); iterador_distancias != end; iterador_distancias++)
        {
            // se aceitavel
            menor_distancia = iterador_distancias->first;
            indice_max = iterador_distancias->second;
            ymax = _treino.at(indice_max)->classe();
        }

        if (ymax==-1)
        {
            indice_max = rand() % _treino.size();
            ymax = _treino.at(indice_max)->classe();
        }
    }

    if (ymax==ponto->classe())
    {
        _corretas++;
        int p = _contador_classes.at(ponto->classe())/_treino.size();
        int n = _treino.size();
        // atualizar registro da classe
    } else
    {
        _incorretas++;
        _treino.push_back(ponto);
    }

    list<pair<float, int> >::iterator iterador_distancias;
    list<pair<float, int> >::iterator end = distancias.end();
    for (iterador_distancias = distancias.begin(); iterador_distancias != end; iterador_distancias++)
    {
        if (iterador_distancias->first < menor_distancia)
        {
            // Atualiza registro
            // Se for pobre, remover do treino
        }
    }
}
