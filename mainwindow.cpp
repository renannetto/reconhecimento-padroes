#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewport = new QGraphicsScene(this);
    ui->graphicsView->setScene(viewport);

    espirais = new GeracaoEspiral(this);
    espirais->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete espirais;
}

void MainWindow::gerarEspiral()
{
    espirais->setVisible(true);
}

Ponto MainWindow::transformar(Ponto * ponto)
{
    float largura = ui->graphicsView->baseSize().width();
    float altura = ui->graphicsView->baseSize().height();

    float novo_x = ponto->x() + (largura/2);
    float novo_y = -(ponto->y() + (altura/2));
    vector<float> coordenadas;
    coordenadas.push_back(novo_x);
    coordenadas.push_back(novo_y);

    return Ponto(coordenadas);
}

void MainWindow::desenharPontos(vector<Ponto*> pontos)
{
    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        Ponto ponto = transformar(pontos.at(indice_ponto));
        viewport->addLine(ponto.x(), ponto.y(), ponto.x(), ponto.y());
    }
}

void MainWindow::classificar()
{

}
