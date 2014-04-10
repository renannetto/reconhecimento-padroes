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
            if (atributo < _ponto_min.at(dimensao))
            {
                _ponto_min.at(dimensao, atributo);
            }
            if (atributo > _ponto_max.at(dimensao))
            {
                _ponto_max.at(dimensao, atributo);
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
        float min = _ponto_min.at(dimensao);
        float max = _ponto_max.at(dimensao);
        float atributo = ponto->at(dimensao);
        ponto->at(dimensao, (atributo-min)/max);
    }
}

int ConjuntoDeDados::classes()
{
    return _classes;
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
