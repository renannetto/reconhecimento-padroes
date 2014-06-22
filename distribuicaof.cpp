#include "distribuicaof.h"

DistribuicaoF::DistribuicaoF()
{
}

void DistribuicaoF::criarDistribuicao(string nome_arquivo)
{
    ifstream arquivo;
    arquivo.open(nome_arquivo.c_str());

    string line;
    getline(arquivo, line);
    stringstream stream(line, stringstream::in);

    int d1, d2;
    stream >> d1;
    stream >> d2;

    for (int linha = 0; linha < d2; linha++)
    {
        getline(arquivo, line);
        stringstream stream(line, stringstream::in);

        for (int coluna = 0; coluna < d1; coluna++)
        {
            float valor;
            stream >> valor;
            pair<int, int> indice(d1, d2);
            _distribuicao[indice] = valor;
        }
    }
}

map<pair<int, int>, float> DistribuicaoF::_distribuicao;
