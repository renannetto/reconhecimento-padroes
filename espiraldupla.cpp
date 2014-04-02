#include "espiraldupla.h"

EspiralDupla::EspiralDupla(int numero_pontos, float a, float b, float passo, int ruido) : ConjuntoDeDados(2)
{
    float theta = passo;
    for (int i=0; i<numero_pontos; i++)
    {
        float raio = a + (b*theta);

        float ponto_x = raio*cos(theta);
        float ponto_y = raio*sin(theta);
        if (ruido > 0)
        {
            ponto_x += rand()%(2*ruido) + ruido;
            ponto_y += rand()%(2*ruido) + ruido;
        }
        vector<float> coordenadas;
        coordenadas.push_back(ponto_x);
        coordenadas.push_back(ponto_y);
        _pontos.push_back(new Ponto(coordenadas, 0));

        ponto_x = -raio*cos(theta);
        ponto_y = -raio*sin(theta);
        if (ruido > 0)
        {
            ponto_x += rand()%(2*ruido) + ruido;
            ponto_y += rand()%(2*ruido) + ruido;
        }
        coordenadas.clear();
        coordenadas.push_back(ponto_x);
        coordenadas.push_back(ponto_y);
        _pontos.push_back(new Ponto(coordenadas, 1));

        theta += passo/raio;
    }
}
