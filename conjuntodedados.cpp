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
