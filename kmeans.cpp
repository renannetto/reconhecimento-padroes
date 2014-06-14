#include "kmeans.h"

KMeans::KMeans(int k)
{
    _k = k;
}

KMeans::~KMeans()
{

}

void KMeans::agrupar(ConjuntoDeDados *dados)
{
    vector<Ponto*> pontos = dados->pontos();

    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        Ponto * ponto = pontos.at(indice_ponto);
        int cluster = rand() % _k;
        ponto->classe(cluster);
    }

    bool mudanca = true;
    while (mudanca)
    {
        vector<Ponto> centroides = atualizarCentroides(pontos);
        mudanca = agruparPontos(&pontos, centroides);
    }
}

vector<Ponto> KMeans::atualizarCentroides(vector<Ponto *> pontos)
{
    vector<Ponto> centroides;
    vector<float> atributos_iniciais;
    for (int dimensao = 0; dimensao < pontos.at(0)->dimensoes(); dimensao++)
    {
        atributos_iniciais.push_back(0.0f);
    }
    for (int cluster = 0; cluster < _k; cluster++)
    {
        Ponto ponto(atributos_iniciais, -1);
        centroides.push_back(ponto);
    }

    vector<int> contador_cluster;
    contador_cluster.resize(_k, 0);

    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        Ponto * ponto = pontos.at(indice_ponto);
        int cluster = ponto->classe();

        contador_cluster.at(cluster) = contador_cluster.at(cluster) + 1;

        Ponto * centroide = &centroides.at(cluster);
        for (int dimensao = 0; dimensao < centroide->dimensoes(); dimensao++)
        {
            float novo_atributo = centroide->at(dimensao) + ponto->at(dimensao);
            centroide->at(dimensao, novo_atributo);
        }
    }

    for (int cluster = 0; cluster < _k; cluster++)
    {
        Ponto * centroide = &centroides.at(cluster);
        for (int dimensao = 0; dimensao < centroide->dimensoes(); dimensao++)
        {
            float novo_atributo = centroide->at(dimensao) / contador_cluster.at(cluster);
            centroide->at(dimensao, novo_atributo);
        }
    }

    return centroides;
}

bool KMeans::agruparPontos(vector<Ponto *> * pontos, vector<Ponto> centroides)
{
    bool mudanca = false;

    for (size_t indice_ponto = 0; indice_ponto < pontos->size(); indice_ponto++)
    {
        Ponto * ponto = pontos->at(indice_ponto);
        float menor_distancia = std::numeric_limits<float>::max();
        int melhor_cluster = -1;
        for (int cluster = 0; cluster < _k; cluster++)
        {
            Ponto * centroide = &centroides.at(cluster);
            float distancia_centroide = _distancia.distancia(ponto, centroide);
            if (distancia_centroide < menor_distancia)
            {
                menor_distancia = distancia_centroide;
                melhor_cluster = cluster;
            }
        }
        if (melhor_cluster != ponto->classe())
        {
            mudanca = true;
        }
        ponto->classe(melhor_cluster);
    }

    return mudanca;
}
