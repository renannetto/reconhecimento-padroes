#include "agrupamentoarvore.h"

AgrupamentoArvore::AgrupamentoArvore(ConjuntoDeDados * dados, DistanciaCluster * distancia)
{
    _dados = dados;
    _distancia = distancia;
}

AgrupamentoArvore::~AgrupamentoArvore()
{
}

NodoDendograma * AgrupamentoArvore::agrupar()
{
    vector<Ponto*> pontos = _dados->pontos_normalizados();
    set<NodoDendograma*> clusters;
    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        vector<Ponto*> pontos_cluster;
        pontos_cluster.push_back(pontos.at(indice_ponto));
        clusters.insert(new NodoDendograma(pontos_cluster, 0.0f, 0, 0));
    }

    while (clusters.size() > 1)
    {
        float menor_distancia = std::numeric_limits<float>::max();
        pair<NodoDendograma*, NodoDendograma* > clusters_proximos;
        for (set<NodoDendograma* >::iterator iterador_cluster1 = clusters.begin(); iterador_cluster1 != clusters.end(); iterador_cluster1++)
        {
            NodoDendograma* cluster1 = *iterador_cluster1;
            set<NodoDendograma* >::iterator iterador_cluster2 = iterador_cluster1;
            iterador_cluster2++;
            for (; iterador_cluster2 != clusters.end(); iterador_cluster2++)
            {
                NodoDendograma* cluster2 = *iterador_cluster2;
                float distancia = _distancia->distancia(cluster1->pontos(), cluster2->pontos());
                if (distancia < menor_distancia)
                {
                    menor_distancia = distancia;
                    clusters_proximos = pair<NodoDendograma*, NodoDendograma* >(cluster1, cluster2);
                }
            }
        }
        clusters.erase(clusters_proximos.first);
        clusters.erase(clusters_proximos.second);
        vector<Ponto*> novo_cluster_pontos = clusters_proximos.first->pontos();
        for (size_t indice_ponto = 0; indice_ponto < clusters_proximos.second->pontos().size(); indice_ponto++)
        {
            novo_cluster_pontos.push_back(clusters_proximos.second->pontos().at(indice_ponto));
        }
        _raiz = new NodoDendograma(novo_cluster_pontos, menor_distancia, clusters_proximos.first, clusters_proximos.second);
        clusters.insert(_raiz);
    }

    _raiz->normalizar(_raiz->distanciaMaxima());

    return _raiz;
}

void AgrupamentoArvore::exportarClassificacao(string nome_arquivo, float corte)
{
    ofstream arquivo;
    arquivo.open(nome_arquivo.c_str());

    vector<NodoDendograma*> nodos_corte;
    nodos_corte = _raiz->obterCorte(nodos_corte, corte);

    vector<Ponto*> pontos = _dados->pontos();
    vector<Ponto*> pontos_normalizados = _dados->pontos_normalizados();

    arquivo << pontos.size() << " " << _dados->dimensoes() << " " << nodos_corte.size() << endl;

    for (size_t indice_ponto = 0; indice_ponto < pontos_normalizados.size(); indice_ponto++)
    {
        Ponto * ponto_normalizado = pontos_normalizados.at(indice_ponto);
        for (size_t indice_cluster = 0; indice_cluster < nodos_corte.size(); indice_cluster++)
        {
            NodoDendograma * cluster = nodos_corte.at(indice_cluster);
            if (cluster->contem(ponto_normalizado))
            {
                ponto_normalizado->classe(indice_cluster);
                pontos.at(indice_ponto)->classe(indice_cluster);
                break;
            }
        }
        pontos.at(indice_ponto)->exportar(arquivo);
    }

    arquivo.close();
}
