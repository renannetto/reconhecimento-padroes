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

    float at(int dimensao);
    void at(int dimensao, float atributo);
    float x();
    float y();

private:
    vector<float> _atributos;
    int _classe;
};

#endif // PONTO_H
