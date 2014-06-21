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
    ConjuntoDeDados * dados_estandardizados = (dados->dimensoes() > 2) ? dados->estandardizar() : dados;
    vector<Ponto*> pontos = dados->pontos();
    vector<Ponto*> pontos_estandardizados = dados_estandardizados->pontos();

    for (size_t indice_ponto = 0; indice_ponto < pontos_estandardizados.size(); indice_ponto++)
    {
        Ponto * ponto = pontos_estandardizados.at(indice_ponto);
        int cluster = rand() % _k;
        ponto->classe(cluster);
    }

    bool mudanca = true;
    while (mudanca)
    {
        vector<Ponto> centroides = atualizarCentroides(pontos_estandardizados);
        mudanca = agruparPontos(&pontos_estandardizados, centroides);
    }

    for (size_t indice_ponto = 0; indice_ponto < pontos_estandardizados.size(); indice_ponto++)
    {
        Ponto * ponto = pontos_estandardizados.at(indice_ponto);
        pontos.at(indice_ponto)->classe(ponto->classe());
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
        Ponto ponto(atributos_iniciais, cluster);
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

float KMeans::taxaF(ConjuntoDeDados *dados)
{
    vector<Ponto*> pontos = dados->pontos();

    vector<Ponto> centroides = atualizarCentroides(pontos);
    vector<int> contador_cluster;
    contador_cluster.resize(_k, 0);
    vector<float> media_global;
    media_global.resize(dados->dimensoes(), 0.0f);

    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        Ponto * ponto = pontos.at(indice_ponto);
        int cluster = ponto->classe();

        contador_cluster.at(cluster) = contador_cluster.at(cluster) + 1;

        for (int dimensao = 0; dimensao < dados->dimensoes(); dimensao++)
        {
            media_global.at(dimensao) = media_global.at(dimensao) + ponto->at(dimensao);
        }
    }

    for (int dimensao = 0; dimensao < dados->dimensoes(); dimensao++)
    {
        media_global.at(dimensao) = media_global.at(dimensao) / pontos.size();
    }

    Ponto variancia_entre;
    for (size_t cluster = 0; cluster < centroides.size(); cluster++)
    {

    }
}
