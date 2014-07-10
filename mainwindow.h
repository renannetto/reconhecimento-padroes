#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>

#include <exception>

#include "canvas.h"

#include "paletadecores.h"
#include "distribuicaof.h"

#include "adicionarruido.h"
#include "removeratributos.h"

#include "kmeans.h"
#include "agrupamentoarvore.h"

#include "distanciasimples.h"
#include "distanciacompleta.h"
#include "distanciamedia.h"

#include "distanciahamming.h"
#include "distanciaeuclides.h"

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

public slots:
    void adicionarRuido();
    void removerAtributos();
    void agruparKMeans();
    void exportarKMeans();
    void construirDendograma();
    void exportarClassificacao();
    void carregarArquivo();
    void carregarDistribuicaoF();

private:
    Ui::MainWindow * _ui;

    AdicionarRuido * _ruido;
    RemoverAtributos * _remover;

    ConjuntoDeDados * _dados;
    KMeans * _kmeans;
    AgrupamentoArvore * _agrupamento_arvore;

    Distancia * distancia();
    DistanciaCluster * distanciaCluster();
};

#endif // MAINWINDOW_H
