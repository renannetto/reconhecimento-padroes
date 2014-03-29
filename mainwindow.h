#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "paletadecores.h"
#include "geracaoespiral.h"
#include "geracaoaleatorio.h"
#include "espiralsimples.h"
#include "nearestneighbor.h"
#include "distanciahamming.h"
#include "distanciaeuclides.h"
#include "capturaeventos.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void desenharPontos(vector<Ponto*> ponto);

public slots:
    void gerarEspiral();
    void gerarAleatorio();
    void classificar();
    void dados(ConjuntoDeDados * dados);

private:
    Ui::MainWindow * _ui;
    QGraphicsScene * _viewport;

    GeracaoEspiral * _espirais;
    GeracaoAleatorio * _aleatorio;

    CapturaEventos * _eventos;

    ConjuntoDeDados * _dados;

    Distancia * distancia();
};

#endif // MAINWINDOW_H
