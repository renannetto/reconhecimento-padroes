#ifndef PALETADECORES_H
#define PALETADECORES_H

#include <vector>
#include <QColor>

using namespace std;

class PaletaDeCores
{
public:
    PaletaDeCores();

    static void criarPaleta();

    static vector<QColor> cores;
};

#endif // PALETADECORES_H
