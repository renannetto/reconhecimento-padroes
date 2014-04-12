#include "ibl3.h"

IBL3::IBL3(Distancia * distancia, int classes, float aceitabilidade, float descarte) : IBL(distancia)
{
    _contador_classes.resize(classes, 0);
    _aceitabilidade = aceitabilidade;
    _descarte = descarte;
}

void IBL3::treinar(Ponto *ponto)
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
        }

        _contador_instancias.at(indice_max)++;
        if (ymax==ponto->classe())
        {
            _corretas++;
            _instancias_corretas.at(indice_max)++;
        } else
        {
            _incorretas++;
            _treino.push_back(ponto);
            _contador_instancias.push_back(0);
            _instancias_corretas.push_back(0);
        }

        for (iterador_distancias = distancias.begin(); iterador_distancias != end; iterador_distancias++)
        {
            if (iterador_distancias->first <= menor_distancia)
            {
                int indice_ponto = iterador_distancias->second;
                int classe = _treino.at(indice_ponto)->classe();
                if (descartavel(indice_ponto, classe))
                {
                    _treino.erase(_treino.begin() + indice_ponto);
                }
            }
        }
    } else
    {
        _treino.push_back(ponto);
        _contador_instancias.push_back(0);
        _instancias_corretas.push_back(0);
    }

    _contador_classes.at(ponto->classe())++;
}

bool IBL3::aceitavel(int indice_ponto, int classe)
{
    if (_contador_instancias.at(indice_ponto)==0 || _treino.size()==0)
    {
        return false;
    }

    float p = _instancias_corretas.at(indice_ponto) / _contador_instancias.at(indice_ponto);
    float n = _contador_instancias.at(indice_ponto);
    float z = _aceitabilidade;
    pair<float, float> intervalo_precisao = intervalo(p, n, z);

    p =  _contador_classes.at(classe) / _treino.size();
    n = _treino.size();
    pair<float, float> intervalo_frequencia = intervalo(p, n, z);

    return intervalo_frequencia.second < intervalo_precisao.first;
}

bool IBL3::descartavel(int indice_ponto, int classe)
{
    if (_contador_instancias.at(indice_ponto)==0 || _treino.size()==0)
    {
        return false;
    }

    float p = _instancias_corretas.at(indice_ponto) / _contador_instancias.at(indice_ponto);
    float n = _contador_instancias.at(indice_ponto);
    float z = _descarte;
    pair<float, float> intervalo_precisao = intervalo(p, n, z);

    p =  _contador_classes.at(classe) / _treino.size();
    n = _treino.size();
    pair<float, float> intervalo_frequencia = intervalo(p, n, z);

    return intervalo_precisao.second < intervalo_frequencia.first;
}

pair<float, float> IBL3::intervalo(float p, float n, float z)
{
    float limite_inferior = (p + (z*z/2*n) - z*sqrt(p*(1-p)/n + z*z/4*n*n)) / (1 + z*z/n);
    float limite_superior = (p + (z*z/2*n) + z*sqrt(p*(1-p)/n + z*z/4*n*n)) / (1 + z*z/n);

    return pair<float, float>(limite_inferior, limite_superior);
}
