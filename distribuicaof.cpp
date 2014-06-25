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

    stream >> _max_d1;
    stream >> _max_d2;

    for (int linha = 1; linha <= _max_d2; linha++)
    {
        getline(arquivo, line);
        stringstream stream(line, stringstream::in);

        for (int coluna = 1; coluna <= _max_d1; coluna++)
        {
            float valor;
            stream >> valor;
            pair<int, int> indice(coluna, linha);
            _distribuicao[indice] = valor;
        }
    }
}

map<pair<int, int>, float> DistribuicaoF::_distribuicao;
int DistribuicaoF::_max_d1;
int DistribuicaoF::_max_d2;
