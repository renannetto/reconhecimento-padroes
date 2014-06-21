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
#include "removeratributos.h"

#include "espiralsimples.h"
#include "classificador.h"
#include "nearestneighbor.h"
#include "ibl1.h"
#include "ibl2.h"
#include "ibl3.h"
#include "ibl4.h"
#include "ibl5.h"

#include "kmeans.h"
#include "agrupamentoarvore.h"

#include "distanciasimples.h"
#include "distanciacompleta.h"
#include "distanciamedia.h"

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
    void removerAtributos(int probabilidade);
    void mostrarPesos(vector<float> pesos);

public slots:
    void gerarEspiral();
    void gerarAleatorio();
    void adicionarRuido();
    void removerAtributos();
    void classificar();
    void agrupar();
    void carregarArquivo();
    void definirClassificador();
    void definirAgrupador();
    void testarPontos();

private:
    Ui::MainWindow * _ui;

    GeracaoEspiral * _espirais;
    GeracaoAleatorio * _aleatorio;
    AdicionarRuido * _ruido;
    RemoverAtributos * _remover;

    ConjuntoDeDados * _dados;
    Classificador * _classificador;
    Agrupador * _agrupador;

    Distancia * distancia();
    DistanciaCluster * distanciaCluster();
};

#endif // MAINWINDOW_H
