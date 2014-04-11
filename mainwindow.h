#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>

#include "paletadecores.h"

#include "geracaoespiral.h"
#include "geracaoaleatorio.h"
#include "espiralsimples.h"

#include "classificador.h"
#include "nearestneighbor.h"
#include "ibl1.h"
#include "ibl2.h"

#include "distanciahamming.h"
#include "distanciaeuclides.h"
#include "canvas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mousePressEvent(float x, float y);
    void desenharPontos(vector<Ponto*> ponto);
    void dados(ConjuntoDeDados * dados);

public slots:
    void gerarEspiral();
    void gerarAleatorio();
    void classificar();
    void carregarArquivo();
    void definirClassificador();

private:
    Ui::MainWindow * _ui;

    GeracaoEspiral * _espirais;
    GeracaoAleatorio * _aleatorio;

    ConjuntoDeDados * _dados;
    Classificador * _classificador;

    Distancia * distancia();

    Ponto transformar(Ponto ponto);
    Ponto transformarInversa(Ponto ponto);
};

#endif // MAINWINDOW_H
