#ifndef PONTO_H
#define PONTO_H

#include <vector>

using namespace std;

class Ponto
{
public:    
    Ponto(vector<float> coordenadas, int classe = -1);

    int dimensoes();
    int classe();

    float at(int dimensao);
    float x();
    float y();

private:
    vector<float> _coordenadas;
    int _classe;
};

#endif // PONTO_H
