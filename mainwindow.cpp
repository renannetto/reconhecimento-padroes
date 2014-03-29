#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

    _viewport = new QGraphicsScene(this);
    _ui->graphicsView->setScene(_viewport);

    _espirais = new GeracaoEspiral(this);
    _espirais->setVisible(false);

    int largura = _ui->graphicsView->width();
    int altura = _ui->graphicsView->height();
    _aleatorio = new GeracaoAleatorio(this, largura, altura);
    _aleatorio->setVisible(false);

    //_eventos = _ui->graphicsView;

    PaletaDeCores::criarPaleta();
}

MainWindow::~MainWindow()
{
    delete _ui;

    delete _espirais;
}

void MainWindow::gerarEspiral()
{
    _espirais->setVisible(true);
}

void MainWindow::gerarAleatorio()
{
    _aleatorio->setVisible(true);
}

void MainWindow::desenharPontos(vector<Ponto*> pontos)
{
    _viewport->clear();
    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        Ponto * ponto = pontos.at(indice_ponto);
        int classe = ponto->classe();
        QColor cor = PaletaDeCores::cores.at(classe);
        _viewport->addEllipse(ponto->x(), ponto->y(), 5.0f, 5.0f, QPen(cor), QBrush(cor));
    }
}

Distancia * MainWindow::distancia()
{
    if (_ui->euclides_radio->isChecked())
    {
        return new DistanciaEuclides();
    }
    return new DistanciaHamming();
}

void MainWindow::classificar()
{
    Distancia * distancia = this->distancia();
    NearestNeighbor * nn = new NearestNeighbor(_dados->pontos(), _dados->classes());

    float ponto_x = _ui->ponto_x->text().toFloat();
    float ponto_y = _ui->ponto_y->text().toFloat();
    vector<float> coordenadas;
    coordenadas.push_back(ponto_x);
    coordenadas.push_back(ponto_y);
    Ponto * ponto = new Ponto(coordenadas);

    int vizinhos = _ui->numero_vizinhos->text().toFloat();

    int classe = nn->classificar(ponto, distancia, vizinhos);
    QColor cor_classe = PaletaDeCores::cores.at(classe);
    _ui->classe_label->setText(QString::number(classe));

    QPalette classe_palette;
    classe_palette.setColor(QPalette::WindowText, cor_classe);
    _ui->classe_label->setPalette(classe_palette);

    delete nn;
}

void MainWindow::dados(ConjuntoDeDados *dados)
{
    _dados = dados;
}
