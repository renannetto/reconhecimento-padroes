#include "ibl3.h"

#include <algorithm>

IBL3::IBL3(Distancia * distancia, int classes, float aceitabilidade, float descarte) : IBL(distancia)
{
    _contador_classes.resize(classes, 0);
    _aceitabilidade = aceitabilidade;
    _descarte = descarte;
    _observados = 0;
}

Ponto * IBL3::treinar(Ponto *ponto)
{
    list<pair<float, int> > distancias = calcularDistancias(ponto);

    float menor_distancia;
    int ymax = -1;
    if (_treino.size()>0)
    {
        int indice_max = -1;
        list<pair<float, int> >::iterator iterador_distancias;
        list<pair<float, int> >::iterator end = distancias.end();
        for (iterador_distancias = distancias.begin(); iterador_distancias != end; iterador_distancias++)
        {
            int indice_ponto = iterador_distancias->second;
            int classe = _treino.at(indice_ponto)->classe();
            if (aceitavel(indice_ponto, classe))
            {
                menor_distancia = iterador_distancias->first;
                indice_max = indice_ponto;
                ymax = classe;
                break;
            }
        }

        if (ymax==-1)
        {
            indice_max = rand() % _treino.size();
            ymax = _treino.at(indice_max)->classe();

            list<pair<float, int> >::iterator iterador_distancias;
            list<pair<float, int> >::iterator end = distancias.end();
            for (iterador_distancias = distancias.begin(); iterador_distancias != end; iterador_distancias++)
            {
                if (iterador_distancias->second==indice_max)
                {
                    menor_distancia = iterador_distancias->first;
                    break;
                }
            }
        }

        if (ymax==ponto->classe())
        {
            _corretas++;
            _treino.at(indice_max)->correta();
        } else
        {
            _incorretas++;
            _treino.push_back(ponto);
        }
        _treino.at(indice_max)->usada();

        Ponto * ponto_max = _treino.at(indice_max);
        vector<int> descartaveis;
        for (iterador_distancias = distancias.begin(); iterador_distancias != end; iterador_distancias++)
        {
            if (iterador_distancias->first <= menor_distancia)
            {
                int indice_ponto = iterador_distancias->second;
                int classe = _treino.at(indice_ponto)->classe();
                if (descartavel(indice_ponto, classe))
                {
                    descartaveis.push_back(indice_ponto);
                }
            }
        }

        vector<Ponto*> novo_treino;
        for (size_t indice_ponto = 0; indice_ponto < _treino.size(); indice_ponto++)
        {
            if (find(descartaveis.begin(), descartaveis.end(), indice_ponto) == descartaveis.end())
            {
                novo_treino.push_back(_treino.at(indice_ponto));
            }
        }
        _treino = novo_treino;

        _contador_classes.at(ponto->classe())++;
        _observados++;

        return ponto_max;
    } else
    {
        _incorretas++;
        _treino.push_back(ponto);
        _contador_classes.at(ponto->classe())++;
        _observados++;

        return 0;
    }
}

bool IBL3::aceitavel(int indice_ponto, int classe)
{
    Ponto * ponto = _treino.at(indice_ponto);
    int contador = ponto->contador();
    int corretas = ponto->corretas();
    if (contador==0 || _treino.size()==0)
    {
        return false;
    }

    float p = (float)corretas / contador;
    float n = contador;
    float z = _aceitabilidade;
    pair<float, float> intervalo_precisao = intervalo(p, n, z);

    p =  (float)_contador_classes.at(classe) / _observados;
    n = _treino.size();
    pair<float, float> intervalo_frequencia = intervalo(p, n, z);

    return intervalo_frequencia.second < intervalo_precisao.first;
}

bool IBL3::descartavel(int indice_ponto, int classe)
{
    Ponto * ponto = _treino.at(indice_ponto);
    int contador = ponto->contador();
    int corretas = ponto->corretas();
    if (contador==0 || _treino.size()==0)
    {
        return false;
    }

    float p = (float)corretas / contador;
    float n = contador;
    float z = _descarte;
    pair<float, float> intervalo_precisao = intervalo(p, n, z);

    p =  (float)_contador_classes.at(classe) / _observados;
    n = _treino.size();
    pair<float, float> intervalo_frequencia = intervalo(p, n, z);

    return intervalo_precisao.second < intervalo_frequencia.first;
}

pair<float, float> IBL3::intervalo(float p, float n, float z)
{
    float limite_inferior = (p + (z*z/2.0f*n) - z*sqrt(p*(1.0f-p)/n + z*z/4.0f*n*n)) / (1.0f + z*z/n);
    float limite_superior = (p + (z*z/2.0f*n) + z*sqrt(p*(1.0f-p)/n + z*z/4.0f*n*n)) / (1.0f + z*z/n);

    return pair<float, float>(limite_inferior, limite_superior);
}
