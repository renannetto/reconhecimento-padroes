#include "kmeans.h"

KMeans::KMeans(ConjuntoDeDados * dados, int k)
{
    _dados = dados;
    _k = k;
}

KMeans::~KMeans()
{

}

void KMeans::agrupar()
{
    vector<Ponto*> pontos_estandardizados = _dados->pontos_normalizados();

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
        if (contador_cluster.at(cluster) > 0)
        {
            *centroide = *centroide / contador_cluster.at(cluster);
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

anova KMeans::testeANOVA()
{
    vector<Ponto*> pontos = _dados->pontos_normalizados();

    vector<Ponto> centroides = atualizarCentroides(pontos);
    vector<int> contador_cluster;
    contador_cluster.resize(_k, 0);
    Ponto media_global(_dados->dimensoes());

    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        Ponto * ponto = pontos.at(indice_ponto);
        int cluster = ponto->classe();

        contador_cluster.at(cluster) = contador_cluster.at(cluster) + 1;

        media_global = media_global + *ponto;
    }

    media_global = media_global / pontos.size();

    Ponto sq_entre(_dados->dimensoes());
    for (size_t cluster = 0; cluster < centroides.size(); cluster++)
    {
        Ponto sq_cluster(_dados->dimensoes());
        sq_cluster = centroides.at(cluster) - media_global;
        sq_cluster = sq_cluster * sq_cluster * contador_cluster.at(cluster);

        sq_entre = sq_entre + sq_cluster;
    }

    Ponto sq_total(_dados->dimensoes());
    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        Ponto * ponto = pontos.at(indice_ponto);
        Ponto sq_ponto(_dados->dimensoes());

        sq_ponto = *ponto - media_global;
        sq_ponto = sq_ponto * sq_ponto;

        sq_total = sq_total + sq_ponto;
    }

    Ponto sq_dentro = sq_total - sq_entre;

    int d1 = min(_k - 1, DistribuicaoF::_max_d1);
    int d2 = min((int)pontos.size() - _k, DistribuicaoF::_max_d2);
    pair<int, int> indice_f(d1, d2);

    Ponto sq_entre_bar = sq_entre / d1;
    Ponto sq_dentro_bar = sq_dentro / d2;

    Ponto f_score = sq_entre_bar / sq_dentro_bar;

    anova resultado_anova;
    for (int dimensao = 0; dimensao < _dados->dimensoes(); dimensao++)
    {
        resultado_anova.sqentre.push_back(sq_entre.at(dimensao));
        resultado_anova.sqdentro.push_back(sq_dentro.at(dimensao));
        resultado_anova.fscore.push_back(f_score.at(dimensao));

        float valor_critico = DistribuicaoF::_distribuicao[indice_f];
        bool resultado = (f_score.at(dimensao) < valor_critico) ? false : true;
        resultado_anova.resultado.push_back(resultado);
    }

    return resultado_anova;
}

void KMeans::exportar(string nome_arquivo)
{
    ofstream arquivo;
    arquivo.open(nome_arquivo.c_str());

    vector<Ponto*> pontos = _dados->pontos();
    vector<Ponto*> pontos_normalizados = _dados->pontos_normalizados();

    arquivo << pontos.size() << " " << _dados->dimensoes() << " " << _k << endl;

    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        Ponto * ponto = pontos.at(indice_ponto);
        Ponto * ponto_normalizado = pontos_normalizados.at(indice_ponto);
        ponto->classe(ponto_normalizado->classe());
        ponto->exportar(arquivo);
    }

    arquivo.close();
}
