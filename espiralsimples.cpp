#include "espiralsimples.h"

EspiralSimples::EspiralSimples(int numero_pontos, float a, float b, float passo, int ruido) : ConjuntoDeDados(1)
{
    float theta = passo;
    for (int i=0; i<numero_pontos; i++)
    {
        float raio = a + (b*theta);

        float ponto_x = raio*cos(theta) + rand()%(2*ruido) + ruido;
        float ponto_y = raio*sin(theta) + rand()%(2*ruido) + ruido;
        vector<float> coordenadas;
        coordenadas.push_back(ponto_x);
        coordenadas.push_back(ponto_y);
        _pontos.push_back(new Ponto(coordenadas, 0));

        theta += passo/raio;
    }
}