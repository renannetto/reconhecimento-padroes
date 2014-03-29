#include "paletadecores.h"

PaletaDeCores::PaletaDeCores()
{
}

void PaletaDeCores::criarPaleta()
{
    cores.push_back(QColor("BLACK"));
    cores.push_back(QColor("RED"));
    cores.push_back(QColor("BLUE"));
    cores.push_back(QColor("GREEN"));
    cores.push_back(QColor("YELLOW"));
    cores.push_back(QColor("CYAN"));
    cores.push_back(QColor("MAGENTA"));
    cores.push_back(QColor("GRAY"));
    cores.push_back(QColor("DARKRED"));
    cores.push_back(QColor("DARKBLUE"));
    cores.push_back(QColor("DARKGREEN"));
    cores.push_back(QColor("DARKYELLOW"));
    cores.push_back(QColor("DARKCYAN"));
    cores.push_back(QColor("DARKMAGENTA"));
    cores.push_back(QColor("DARKGRAY"));
}

vector<QColor> PaletaDeCores::cores;
