#ifndef PONTO_H
#define PONTO_H

#include <vector>

using namespace std;

class Ponto
{
public:    
    Ponto(vector<float> coordenadas);

    int dimensoes();
    const vector<float> coordenadas();

    float x();
    float y();

private:
    vector<float> _coordenadas;
};

#endif // PONTO_H
