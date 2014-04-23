#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>

#include <exception>

#include "paletadecores.h"

#include "geracaoespiral.h"
#include "geracaoaleatorio.h"
#include "adicionarruido.h"

#include "espiralsimples.h"
#include "classificador.h"
#include "nearestneighbor.h"
#include "ibl1.h"
#include "ibl2.h"
#include "ibl3.h"
#include "ibl4.h"
#include "ibl5.h"

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
    void dados(ConjuntoDeDados * dados);
    void adicionarRuido(int incidencia, int ruido);
    void mostrarPesos(vector<float> pesos);

public slots:
    void gerarEspiral();
    void gerarAleatorio();
    void adicionarRuido();
    void classificar();
    void carregarArquivo();
    void definirClassificador();
    void testarPontos();

private:
    Ui::MainWindow * _ui;

    GeracaoEspiral * _espirais;
    GeracaoAleatorio * _aleatorio;
    AdicionarRuido * _ruido;

    ConjuntoDeDados * _dados;
    Classificador * _classificador;

    Distancia * distancia();
};

#endif // MAINWINDOW_H
