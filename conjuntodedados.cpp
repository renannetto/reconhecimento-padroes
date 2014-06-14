#include "conjuntodedados.h"

ConjuntoDeDados::ConjuntoDeDados(int classes)
{
    _classes = classes;
}

ConjuntoDeDados::ConjuntoDeDados(string nome_arquivo)
{
    ifstream arquivo;
    arquivo.open(nome_arquivo.c_str());

    string line;
    getline(arquivo, line);
    stringstream stream(line, stringstream::in);

    int numero_pontos;
    stream >> numero_pontos;

    int atributos;
    stream >> atributos;

    stream >> _classes;

    for (int indice_ponto = 0; indice_ponto < numero_pontos; indice_ponto++)
    {
        getline(arquivo, line);
        stringstream stream(line, stringstream::in);

        vector<float> coordenadas;
        for (int indice_atributo = 0; indice_atributo < atributos; indice_atributo++)
        {
            float atributo;
            stream >> atributo;
            coordenadas.push_back(atributo);
        }
        int classe;
        stream >> classe;
        _pontos.push_back(new Ponto(coordenadas, classe));
    }

    if (dimensoes()>2)
    {
        normalizar();
    }
}

void ConjuntoDeDados::normalizar()
{
    _ponto_min = *_pontos.at(0);
    _ponto_max = *_pontos.at(0);

    for (size_t indice_ponto = 1; indice_ponto < _pontos.size(); indice_ponto++)
    {
        Ponto * ponto = _pontos.at(indice_ponto);
        for (int dimensao = 0; dimensao < ponto->dimensoes(); dimensao++)
        {
            float atributo = ponto->at(dimensao);
            if (atributo != -1)
            {
                if (atributo < _ponto_min.at(dimensao) || _ponto_min.at(dimensao)==-1)
                {
                    _ponto_min.at(dimensao, atributo);
                }
                if (atributo > _ponto_max.at(dimensao) || _ponto_max.at(dimensao)==-1)
                {
                    _ponto_max.at(dimensao, atributo);
                }
            }
        }
    }

    for (size_t indice_ponto = 0; indice_ponto < _pontos.size(); indice_ponto++)
    {
        normalizarPonto(_pontos.at(indice_ponto));
    }
}

void ConjuntoDeDados::normalizarPonto(Ponto *ponto)
{
    for (int dimensao = 0; dimensao < ponto->dimensoes(); dimensao++)
    {
        if (ponto->at(dimensao) != -1)
        {
            float min = _ponto_min.at(dimensao);
            float max = _ponto_max.at(dimensao);
            float atributo = ponto->at(dimensao);
            ponto->at(dimensao, (atributo-min)/max);
        }
    }
}

void ConjuntoDeDados::estandardizar()
{
    vector<float> media;
    media.resize(dimensoes(), 0.0f);
    vector<float> desvio_padrao;
    desvio_padrao.resize(dimensoes(), 0.0f);

    for (size_t indice_ponto = 0; indice_ponto < _pontos.size(); indice_ponto++)
    {
        Ponto * ponto = _pontos.at(indice_ponto);
        for (int dimensao = 0; dimensao < dimensoes(); dimensao++)
        {
            media.at(dimensao) = media.at(dimensao) + ponto->at(dimensao);
        }
    }
    for (int dimensao = 0; dimensao < dimensoes(); dimensao++)
    {
        media.at(dimensao) = media.at(dimensao) / _pontos.size();
    }

    for (size_t indice_ponto = 0; indice_ponto < _pontos.size(); indice_ponto++)
    {
        Ponto * ponto = _pontos.at(indice_ponto);
        for (int dimensao = 0; dimensao < dimensoes(); dimensao++)
        {
            desvio_padrao.at(dimensao) = desvio_padrao.at(dimensao) + ((ponto->at(dimensao)-media.at(dimensao))*(ponto->at(dimensao)-media.at(dimensao)));
        }
    }
    for (int dimensao = 0; dimensao < dimensoes(); dimensao++)
    {
        desvio_padrao.at(dimensao) = desvio_padrao.at(dimensao) / (_pontos.size()-1);
    }

    for (size_t indice_ponto = 0; indice_ponto < _pontos.size(); indice_ponto++)
    {
        Ponto * ponto = _pontos.at(indice_ponto);
        ponto->estandardizar(media, desvio_padrao);
    }
}

void ConjuntoDeDados::adicionarRuido(int incidencia, int ruido)
{
    for (size_t indice_ponto = 0; indice_ponto < _pontos.size(); indice_ponto++)
    {
        int chance_rudio = rand() % 100;
        if (chance_rudio < incidencia)
        {
            Ponto * ponto = _pontos.at(indice_ponto);
            for (int dimensao = 0; dimensao < ponto->dimensoes(); dimensao++)
            {
                float atributo = ponto->at(dimensao);
                int ruido_dimensao = rand()%(2*ruido) - ruido;
                ponto->at(dimensao, atributo+ruido_dimensao);
            }
        }
    }
}

void ConjuntoDeDados::removerAtributos(int probabilidade)
{
    for (size_t indice_ponto = 0; indice_ponto < _pontos.size(); indice_ponto++)
    {
        int chance_remocao = rand() % 100;
        if (chance_remocao < probabilidade)
        {
            Ponto * ponto = _pontos.at(indice_ponto);
            int dimensao = rand() % ponto->dimensoes();
            ponto->at(dimensao, -1);
        }
    }
}

int ConjuntoDeDados::classes()
{
    return _classes;
}

void ConjuntoDeDados::classes(int classes)
{
    _classes = classes;
}

const vector<Ponto*> ConjuntoDeDados::pontos()
{
    return _pontos;
}

int ConjuntoDeDados::dimensoes()
{
    if (_pontos.size()==0)
    {
        return 0;
    }
    return _pontos.at(0)->dimensoes();
}
