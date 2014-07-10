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

    int largura = _ui->view_dendograma->width();
    int altura = _ui->view_dendograma->height();
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

void MainWindow::dados(ConjuntoDeDados *dados)
{
    if (_dados)
    {
        delete _dados;
    }

    _dados = dados;
}

void MainWindow::adicionarRuido(int incidencia, int ruido)
{
    if (_dados)
    {
        _dados->adicionarRuido(incidencia, ruido);
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
        int k = _ui->kmeans_k->value();
        _kmeans = new KMeans(_dados, k);
        _kmeans->agrupar();

        anova resultado_anova = _kmeans->testeANOVA(_dados);
        QString sqentre_string, sqdentro_string, fscore_string, resultado_string;
        for (int dimensao = 0; dimensao < _dados->dimensoes(); dimensao++)
        {
            sqentre_string += QString::number(resultado_anova.sqentre.at(dimensao)) + "\n";
            sqdentro_string += QString::number(resultado_anova.sqdentro.at(dimensao)) + "\n";
            fscore_string += QString::number(resultado_anova.fscore.at(dimensao)) + "\n";
            resultado_string += (resultado_anova.resultado.at(dimensao)) ? "passou\n" : "falhou\n";
        }
        _ui->sqentre_edit->setText(sqentre_string);
        _ui->sqdentro_edit->setText(sqdentro_string);
        _ui->fscore_edit->setText(fscore_string);
        _ui->resultado_edit->setText(resultado_string);
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário carregar um conjunto de dados primeiro!");
        message_box.exec();
    }
}

void MainWindow::exportarKMeans()
{
    if (_kmeans)
    {
        QString nome_arquivo = QFileDialog::getSaveFileName(this, tr("Arquivo para exportar"), "");
        _kmeans->exportar(nome_arquivo.toStdString());
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário construir um dendograma primeiro!");
        message_box.exec();
    }
}

void MainWindow::construirDendograma()
{
    if (_dados)
    {
        _agrupamento_arvore = new AgrupamentoArvore(_dados, distanciaCluster());
        NodoDendograma * dendograma = _agrupamento_arvore->agrupar();
        dendograma->desenhar(_ui->view_dendograma, _ui->view_dendograma->height() / 2);
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário carregar um conjunto de dados primeiro!");
        message_box.exec();
    }
}

void MainWindow::exportarClassificacao()
{
    if (_agrupamento_arvore)
    {
        QString nome_arquivo = QFileDialog::getSaveFileName(this, tr("Arquivo para exportar"), "");
        float corte = _ui->corte_dendograma->text().toFloat();
        _agrupamento_arvore->exportarClassificacao(nome_arquivo.toStdString(), corte);
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário construir um dendograma primeiro!");
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
