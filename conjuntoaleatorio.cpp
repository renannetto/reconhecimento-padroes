#include "conjuntoaleatorio.h"

ConjuntoAleatorio::ConjuntoAleatorio(int classes, int numero_pontos, int min_x, int min_y, int max_x, int max_y) : ConjuntoDeDados(classes)
{
    for (int indice_ponto = 0; indice_ponto < numero_pontos; indice_ponto++)
    {
        float x = (float)(rand() % (max_x-min_x) + min_x);
        float y = (float)(rand() % (max_y-min_y) + min_y);
        vector<float> coordenadas;
        coordenadas.push_back(x);
        coordenadas.push_back(y);
        int classe = rand() % classes;
        _pontos.push_back(new Ponto(coordenadas, classe));
    }
}
