#include "capturaeventos.h"
#include "mainwindow.h"

CapturaEventos::CapturaEventos(QWidget * parent) : QGraphicsView(parent)
{
    _main_window = (MainWindow*) parent;
}

void CapturaEventos::mousePressEvent(QMouseEvent *e)
{
    cout << e->x() << endl;
    cout << e->y() << endl;
}
