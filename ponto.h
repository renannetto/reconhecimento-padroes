#ifndef PONTO_H
#define PONTO_H

#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Ponto
{
public:
    Ponto();
    Ponto(int dimensoes, int classe = -1);
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

    Ponto * estandardizar(vector<float> media, vector<float> desvio_padrao);

    void exportar(ofstream &stream);

    Ponto operator+(const Ponto &other);
    Ponto operator-(const Ponto &other);
    Ponto operator*(const Ponto &other);
    Ponto operator/(const Ponto &other);
    Ponto operator/(const int escalar);
    Ponto operator*(const int escalar);

private:
    vector<float> _atributos;
    int _classe;
    int _contador;
    int _corretas;
};

#endif // PONTO_H
