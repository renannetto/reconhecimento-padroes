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
    int dimensoes = pontos.at(0)->dimensoes();
    for (int cluster = 0; cluster < _k; cluster++)
    {
        Ponto ponto(dimensoes, cluster);
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
        *centroide = *centroide + *ponto;
    }

    for (int cluster = 0; cluster < _k; cluster++)
    {
        Ponto * centroide = &centroides.at(cluster);
        *centroide = *centroide / contador_cluster.at(cluster);
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

bool KMeans::testeF(ConjuntoDeDados *dados)
{
    vector<Ponto*> pontos = dados->pontos();

    vector<Ponto> centroides = atualizarCentroides(pontos);
    vector<int> contador_cluster;
    contador_cluster.resize(_k, 0);
    Ponto media_global(dados->dimensoes());

    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        Ponto * ponto = pontos.at(indice_ponto);
        int cluster = ponto->classe();

        contador_cluster.at(cluster) = contador_cluster.at(cluster) + 1;

        media_global = media_global + *ponto;
    }

    media_global = media_global / pontos.size();

    Ponto variancia_entre(dados->dimensoes());
    for (size_t cluster = 0; cluster < centroides.size(); cluster++)
    {
        Ponto variancia_cluster(dados->dimensoes());
        variancia_cluster = centroides.at(cluster) - media_global;
        variancia_cluster = variancia_cluster * variancia_cluster * contador_cluster.at(cluster);

        variancia_entre = variancia_entre + variancia_cluster;
    }

    Ponto variancia_total(dados->dimensoes());
    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        Ponto * ponto = pontos.at(indice_ponto);
        Ponto variancia_ponto(dados->dimensoes());

        variancia_ponto = *ponto - media_global;
        variancia_ponto = variancia_ponto * variancia_ponto;

        variancia_total = variancia_total + variancia_ponto;
    }

    Ponto variancia_dentro = variancia_total - variancia_entre;

    int d1 = _k - 1;
    int d2 = pontos.size() - _k;
    pair<int, int> indice_f(d1, d2);

    Ponto variancia_entre_bar = variancia_entre / d1;
    Ponto variancia_dentro_bar = variancia_dentro / d2;

    Ponto f_score = variancia_entre_bar / variancia_dentro_bar;

    for (int dimensao = 0; dimensao < dados->dimensoes(); dimensao++)
    {
        if (f_score.at(dimensao) > DistribuicaoF::_distribuicao[indice_f])
        {
            return false;
        }
    }

    return true;
}
