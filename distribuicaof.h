#ifndef DISTRIBUICAOF_H
#define DISTRIBUICAOF_H

#include <string>
#include <fstream>
#include <sstream>
#include <map>

#define F_SCORE_TABLE "../reconhecimento-padroes/dados/f_score_table"

using namespace std;

class DistribuicaoF
{
public:
    DistribuicaoF();

    static void criarDistribuicao(string nome_arquivo);

    static map<pair<int, int>, float> _distribuicao;
    static int _max_d1;
    static int _max_d2;
};

#endif // DISTRIBUICAOF_H
