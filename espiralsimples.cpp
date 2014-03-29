#include "espiralsimples.h"

EspiralSimples::EspiralSimples(int numero_pontos) : ConjuntoDeDados(1)
{
    float a = 1.0f;
    float b = 1.0f;
    float passo = 1.0f;

    float theta = 0.0f;
    for (int indice_ponto = 0; indice_ponto < numero_pontos; indice_ponto++)
    {
        float raio = a + (b*theta);

        float ponto_x = raio*cos(theta);
        float ponto_y = raio*sin(theta);
        vector<float> coordenadas;
        coordenadas.push_back(ponto_x);
        coordenadas.push_back(ponto_y);
        _pontos.push_back(new Ponto(coordenadas, 0));

        theta += passo;
    }
}
