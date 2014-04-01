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

    _ui->graphicsView->fixarMainWindow(this);

    PaletaDeCores::criarPaleta();
}

MainWindow::~MainWindow()
{
    delete _ui;

    delete _espirais;
}

Ponto MainWindow::transformar(Ponto ponto)
{
    int largura = _ui->graphicsView->width();
    int altura = _ui->graphicsView->height();

    float novo_ponto_x = ponto.x() + (largura/2);
    float novo_ponto_y = (altura/2)-ponto.y();
    vector<float> coordenadas;
    coordenadas.push_back(novo_ponto_x);
    coordenadas.push_back(novo_ponto_y);
    return Ponto(coordenadas, ponto.classe());
}

Ponto MainWindow::transformarInversa(Ponto ponto)
{
    int largura = _ui->graphicsView->width();
    int altura = _ui->graphicsView->height();

    float novo_ponto_x = ponto.x()-(largura/2);
    float novo_ponto_y = (altura/2)-ponto.y();
    vector<float> coordenadas;
    coordenadas.push_back(novo_ponto_x);
    coordenadas.push_back(novo_ponto_y);
    return Ponto(coordenadas, ponto.classe());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    vector<float> coordenadas;
    coordenadas.push_back(event->x());
    coordenadas.push_back(event->y());
    Ponto ponto = transformarInversa(Ponto(coordenadas));

    int largura = _ui->graphicsView->width();
    int altura = _ui->graphicsView->height();
    if (ponto.x() > -largura/2 && ponto.x() < largura/2 && ponto.y() > -altura/2 && ponto.y() < altura/2)
    {
        _ui->ponto_x->setText(QString::number(ponto.x()));
        _ui->ponto_y->setText(QString::number(ponto.y()));
    }
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
        Ponto ponto = transformar(*pontos.at(indice_ponto));
        int classe = ponto.classe();
        QColor cor = PaletaDeCores::cores.at(classe);
        _viewport->addEllipse(ponto.x(), ponto.y(), 5.0f, 5.0f, QPen(cor), QBrush(cor));
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

    Ponto * ponto;
    if (_dados->dimensoes()==2)
    {
        float ponto_x = _ui->ponto_x->text().toFloat();
        float ponto_y = _ui->ponto_y->text().toFloat();
        vector<float> coordenadas;
        coordenadas.push_back(ponto_x);
        coordenadas.push_back(ponto_y);
        ponto = new Ponto(coordenadas);
    } else
    {
        string atributos_texto = _ui->novo_ponto->text().toStdString();
        stringstream stream(atributos_texto, stringstream::in);
        vector<float> atributos;
        for (int dimensao = 0; dimensao < _dados->dimensoes(); dimensao++)
        {
            float atributo;
            stream >> atributo;
            atributos.push_back(atributo);
        }
        ponto = new Ponto(atributos);
    }

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

void MainWindow::carregarArquivo()
{
    QString nome_arquivo = QFileDialog::getOpenFileName(this, tr("Open file"), "");
    _dados = new ConjuntoDeDados(nome_arquivo.toStdString());
}
