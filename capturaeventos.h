#ifndef EVENTOSMOUSE_H
#define EVENTOSMOUSE_H

#include <QGraphicsView>
#include <QMouseEvent>

class MainWindow;

class CapturaEventos : QGraphicsView
{
public:
    CapturaEventos(QWidget * parent);

public slots:
    void mousePressEvent(QMouseEvent * e);

private:
    MainWindow * _main_window;
};

#endif // EVENTOSMOUSE_H
