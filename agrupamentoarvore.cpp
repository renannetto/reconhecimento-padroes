#include "agrupamentoarvore.h"

AgrupamentoArvore::AgrupamentoArvore(DistanciaCluster * distancia, int min_class, int max_class, float plato)
{
    _distancia = distancia;
    _min_class = min_class;
    _max_class = max_class;
    _plato = plato;
}

AgrupamentoArvore::~AgrupamentoArvore()
{
}

void AgrupamentoArvore::agrupar(ConjuntoDeDados * dados)
{
    ConjuntoDeDados * dados_estandardizados = dados->estandardizar();
    vector<Ponto*> pontos = dados->pontos();
    vector<Ponto*> pontos_estandardizados = dados_estandardizados->pontos();
    set<vector<Ponto*> > clusters;
    vector<vector<Ponto*> > clusters_formados;
    for (size_t indice_ponto = 0; indice_ponto < pontos_estandardizados.size(); indice_ponto++)
    {
        vector<Ponto*> cluster;
        cluster.push_back(pontos_estandardizados.at(indice_ponto));
        clusters.insert(cluster);
    }

    int classes = 0;
    float passo = 0.0f;
    float distancia_anterior = 0.0f;
    while (classes < _min_class || (classes <= _max_class && passo < _plato))
    {
        float menor_distancia = std::numeric_limits<float>::max();
        pair<vector<Ponto*>, vector<Ponto*> > clusters_proximos;
        for (set<vector<Ponto*> >::iterator iterador_cluster1 = clusters.begin(); iterador_cluster1 != clusters.end(); iterador_cluster1++)
        {
            vector<Ponto*> cluster1 = *iterador_cluster1;
            set<vector<Ponto*> >::iterator iterador_cluster2 = iterador_cluster1;
            iterador_cluster2++;
            for (; iterador_cluster2 != clusters.end(); iterador_cluster2++)
            {
                vector<Ponto*> cluster2 = *iterador_cluster2;
                float distancia = _distancia->distancia(cluster1, cluster2);
                if (distancia < menor_distancia)
                {
                    menor_distancia = distancia;
                    clusters_proximos = pair<vector<Ponto*>, vector<Ponto*> >(cluster1, cluster2);
                }
            }
        }
        clusters.erase(clusters_proximos.first);
        clusters.erase(clusters_proximos.second);
        vector<Ponto*> novo_cluster = clusters_proximos.first;
        for (size_t indice_ponto = 0; indice_ponto < clusters_proximos.second.size(); indice_ponto++)
        {
            novo_cluster.push_back(clusters_proximos.second.at(indice_ponto));
        }
        clusters.insert(novo_cluster);
        clusters_formados.push_back(novo_cluster);

        classes++;
        passo = menor_distancia - distancia_anterior;
        distancia_anterior = menor_distancia;
    }

    dados->classes(classes);

    for (size_t indice_ponto = 0; indice_ponto < pontos_estandardizados.size(); indice_ponto++)
    {
        Ponto * ponto = pontos_estandardizados.at(indice_ponto);
        float menor_distancia = numeric_limits<float>::max();
        int classe = -1;
        for (size_t indice_cluster = 0; indice_cluster < clusters_formados.size(); indice_cluster++)
        {
            vector<Ponto*> cluster = clusters_formados.at(indice_cluster);
            float distancia = _distancia->distancia(ponto, cluster);
            if (distancia < menor_distancia)
            {
                menor_distancia = distancia;
                classe = indice_cluster;
            }
        }
        pontos.at(indice_ponto)->classe(classe);
    }
}
