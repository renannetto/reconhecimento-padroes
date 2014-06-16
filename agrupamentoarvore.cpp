#include "agrupamentoarvore.h"

AgrupamentoArvore::AgrupamentoArvore(DistanciaCluster * distancia)
{
    _distancia = distancia;
}

AgrupamentoArvore::~AgrupamentoArvore()
{
}

void AgrupamentoArvore::agrupar(ConjuntoDeDados * dados)
{
    dados->estandardizar();
    vector<Ponto*> pontos = dados->pontos();
    set<vector<Ponto*> > clusters;
    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        vector<Ponto*> cluster;
        cluster.push_back(pontos.at(indice_ponto));
        clusters.insert(cluster);
    }

    int _classes = 3;
    int classes = 0;
    while (classes < _classes)
    {
        float menor_distancia = std::numeric_limits<float>::max();
        pair<vector<Ponto*>, vector<Ponto*> > clusters_proximos;
        for (set<vector<Ponto*> >::iterator iterador_cluster1 = clusters.begin(); iterador_cluster1 != clusters.end(); iterador_cluster1++)
        {
            vector<Ponto*> cluster1 = *iterador_cluster1;
            set<vector<Ponto*> >::iterator iterador_cluster2 = iterador_cluster1;
            iterador_cluster2++;
            for (iterador_cluster2; iterador_cluster2 != clusters.end(); iterador_cluster2++)
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
        classes++;
    }
}
