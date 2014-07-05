#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

    _espirais = new GeracaoEspiral(this);
    _espirais->setVisible(false);

    int largura = _ui->view_dados->width();
    int altura = _ui->view_dados->height();
    _aleatorio = new GeracaoAleatorio(this, largura, altura);
    _aleatorio->setVisible(false);

    _ruido = new AdicionarRuido(this);
    _ruido->setVisible(false);

    _remover = new RemoverAtributos(this);
    _remover->setVisible(false);

    PaletaDeCores::criarPaleta();

    _dados = 0;
}

MainWindow::~MainWindow()
{
    delete _ui;

    delete _espirais;
    delete _aleatorio;
    delete _ruido;
    delete _remover;
}

void MainWindow::gerarEspiral()
{
    _espirais->setVisible(true);
}

void MainWindow::gerarAleatorio()
{
    _aleatorio->setVisible(true);
}

void MainWindow::adicionarRuido()
{
    if (_dados)
    {
        _ruido->setVisible(true);
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário carregar um conjunto de dados primeiro!");
        message_box.exec();
    }
}

void MainWindow::removerAtributos()
{
    if (_dados)
    {
        _remover->setVisible(true);
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário carregar um conjunto de dados primeiro!");
        message_box.exec();
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

DistanciaCluster * MainWindow::distanciaCluster()
{
    Distancia * distancia = this->distancia();
    if (_ui->distancia_simples->isChecked())
    {
        return new DistanciaSimples(distancia);
    }
    if (_ui->distancia_completa->isChecked())
    {
        return new DistanciaCompleta(distancia);
    }
    return new DistanciaMedia(distancia);
}

void MainWindow::mostrarPesos(vector<float> pesos)
{
    ostringstream stream_pesos;
    for (size_t dimensao = 0; dimensao < pesos.size(); dimensao++)
    {
        float peso = pesos.at(dimensao);
        stream_pesos << peso << " ";
    }
    _ui->pesos->setText(QString::fromStdString(stream_pesos.str()));
}

void MainWindow::dados(ConjuntoDeDados *dados)
{
    if (_dados)
    {
        delete _dados;
    }

    _dados = dados;
    if (_dados->dimensoes()==2)
    {
        _ui->view_dados->desenharPontos(dados->pontos());
    }
}

void MainWindow::adicionarRuido(int incidencia, int ruido)
{
    if (_dados)
    {
        _dados->adicionarRuido(incidencia, ruido);
        _ui->view_dados->desenharPontos(_dados->pontos());
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário carregar um conjunto de dados primeiro!");
        message_box.exec();
    }
}

void MainWindow::removerAtributos(int probabilidade)
{
    if (_dados)
    {
        _dados->removerAtributos(probabilidade);
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário carregar um conjunto de dados primeiro!");
        message_box.exec();
    }
}

void MainWindow::agruparKMeans()
{
    if (_dados)
    {

    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário carregar um conjunto de dados primeiro!");
        message_box.exec();
    }
}

void MainWindow::construirDendograma()
{
    if (_dados)
    {

    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário carregar um conjunto de dados primeiro!");
        message_box.exec();
    }
}

void MainWindow::carregarArquivo()
{
    QString nome_arquivo = QFileDialog::getOpenFileName(this, tr("Abrir arquivo de dados"), "");

    try {
        dados(new ConjuntoDeDados(nome_arquivo.toStdString()));
    } catch (exception &e)
    {
        QMessageBox message_box;
        message_box.setText("Não foi possível carregar a base de dados selecionada");
        message_box.exec();
    }
}

void MainWindow::carregarDistribuicaoF()
{
    QString nome_arquivo = QFileDialog::getOpenFileName(this, tr("Abrir distribuição F"), "");

    try {
        DistribuicaoF::criarDistribuicao(nome_arquivo.toStdString());
    } catch (exception &e)
    {
        QMessageBox message_box;
        message_box.setText("Não foi possível carregar a base de dados selecionada");
        message_box.exec();
    }
}
