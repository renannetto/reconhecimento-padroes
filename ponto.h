#ifndef PONTO_H
#define PONTO_H

#include <vector>

using namespace std;

class Ponto
{
public:
    Ponto();
    Ponto(vector<float> atributos, int classe = -1);

    int dimensoes();
    int classe();
    void classe(int classe);

    float at(int dimensao);
    void at(int dimensao, float atributo);
    float x();
    float y();

    void usada();
    void correta();

    int contador();
    int corretas();

    bool ambosConhecidos(Ponto * ponto2, int dimensao);

    void estandardizar(vector<float> media, vector<float> desvio_padrao);

private:
    vector<float> _atributos;
    int _classe;
    int _contador;
    int _corretas;
};

#endif // PONTO_H
