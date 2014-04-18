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

    int largura = _ui->graphicsView->width();
    int altura = _ui->graphicsView->height();
    _aleatorio = new GeracaoAleatorio(this, largura, altura);
    _aleatorio->setVisible(false);

    _ui->graphicsView->fixarMainWindow(this);

    PaletaDeCores::criarPaleta();

    _dados = 0;
    _classificador = 0;
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

void MainWindow::mousePressEvent(float x, float y)
{
    vector<float> coordenadas;
    coordenadas.push_back(x);
    coordenadas.push_back(y);
    Ponto ponto(coordenadas);

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
    _ui->graphicsView->limpar();
    for (size_t indice_ponto = 0; indice_ponto < pontos.size(); indice_ponto++)
    {
        _ui->graphicsView->desenharPonto(*pontos.at(indice_ponto));
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

void MainWindow::definirClassificador()
{
    if (_dados)
    {
        if (_classificador)
        {
            delete _classificador;
        }

        Distancia * distancia = this->distancia();
        if (_ui->neighbor_radio->isChecked())
        {
             int vizinhos = _ui->numero_vizinhos->text().toFloat();
             _classificador = new NearestNeighbor(distancia, _dados, vizinhos);
        } else if (_ui->ibl1_radio->isChecked())
        {
            _classificador = new IBL1(distancia);
            ((IBL*)_classificador)->treinar(_dados);
            if (_dados->dimensoes()==2)
            {
                desenharPontos(((IBL*)_classificador)->treino());
            }

            int corretas = ((IBL*)_classificador)->corretas();
            int incorretas = ((IBL*)_classificador)->incorretas();
            _ui->corretas->setText(QString::number(corretas));
            _ui->incorretas->setText(QString::number(incorretas));
        } else if (_ui->ibl2_radio->isChecked())
        {
            _classificador = new IBL2(distancia);
            ((IBL*)_classificador)->treinar(_dados);
            if (_dados->dimensoes()==2)
            {
                desenharPontos(((IBL*)_classificador)->treino());
            }

            int corretas = ((IBL*)_classificador)->corretas();
            int incorretas = ((IBL*)_classificador)->incorretas();
            _ui->corretas->setText(QString::number(corretas));
            _ui->incorretas->setText(QString::number(incorretas));
        } else if (_ui->ibl3_radio->isChecked())
        {
            _classificador = new IBL3(distancia, _dados->classes());
            ((IBL*)_classificador)->treinar(_dados);
            if (_dados->dimensoes()==2)
            {
                desenharPontos(((IBL*)_classificador)->treino());
            }

            int corretas = ((IBL*)_classificador)->corretas();
            int incorretas = ((IBL*)_classificador)->incorretas();
            _ui->corretas->setText(QString::number(corretas));
            _ui->incorretas->setText(QString::number(incorretas));
        } else if (_ui->ibl4_radio->isChecked())
        {
            _classificador = new IBL4(distancia, _dados->classes(), _dados->dimensoes());
            ((IBL*)_classificador)->treinar(_dados);
            if (_dados->dimensoes()==2)
            {
                desenharPontos(((IBL*)_classificador)->treino());
            }

            int corretas = ((IBL*)_classificador)->corretas();
            int incorretas = ((IBL*)_classificador)->incorretas();
            _ui->corretas->setText(QString::number(corretas));
            _ui->incorretas->setText(QString::number(incorretas));
        } else if (_ui->ibl5_radio->isChecked())
        {
            _classificador = new IBL5(distancia, _dados->classes(), _dados->dimensoes());
            ((IBL*)_classificador)->treinar(_dados);
            if (_dados->dimensoes()==2)
            {
                desenharPontos(((IBL*)_classificador)->treino());
            }

            int corretas = ((IBL*)_classificador)->corretas();
            int incorretas = ((IBL*)_classificador)->incorretas();
            _ui->corretas->setText(QString::number(corretas));
            _ui->incorretas->setText(QString::number(incorretas));
        }
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário carregar um conjunto de dados primeiro!");
        message_box.exec();
    }
}

void MainWindow::testarPontos()
{
    if (_dados && _dados->dimensoes() == 2 && _classificador)
    {
        int distancia_pontos = _ui->distancia_pontos->value();
        int width = _ui->graphicsView->width();
        int height = _ui->graphicsView->height();
        for (int x = -width/2; x < width/2; x += distancia_pontos)
        {
            for (int y = -height/2; y < height/2; y += distancia_pontos)
            {
                vector<float> atributos;
                atributos.push_back(x);
                atributos.push_back(y);

                Ponto ponto(atributos);
                int classe = _classificador->classificar(&ponto);
                _ui->graphicsView->desenharPonto(Ponto(atributos, classe));
            }
        }
    } else if (!_dados || _dados->dimensoes() > 2)
    {
        QMessageBox message_box;
        message_box.setText("É necessário carregar um conjunto de dados 2D!");
        message_box.exec();
    } else {
        QMessageBox message_box;
        message_box.setText("É necessário definir um classificador primeiro!");
        message_box.exec();
    }
}

void MainWindow::classificar()
{
    if (_classificador)
    {
        vector<float> atributos;
        if (_dados->dimensoes()==2)
        {
            float ponto_x = _ui->ponto_x->text().toFloat();
            float ponto_y = _ui->ponto_y->text().toFloat();
            atributos.push_back(ponto_x);
            atributos.push_back(ponto_y);
        } else
        {
            string atributos_texto = _ui->novo_ponto->text().toStdString();
            stringstream stream(atributos_texto, stringstream::in);
            for (int dimensao = 0; dimensao < _dados->dimensoes(); dimensao++)
            {
                float atributo;
                stream >> atributo;
                atributos.push_back(atributo);
            }
        }

        Ponto ponto(atributos);
        if (_dados->dimensoes()>2)
        {
            _dados->normalizarPonto(&ponto);
        }

        int classe = _classificador->classificar(&ponto);
        QColor cor_classe = PaletaDeCores::cores.at(classe);
        _ui->classe_label->setText(QString::number(classe));

        QPalette classe_palette;
        classe_palette.setColor(QPalette::WindowText, cor_classe);
        _ui->classe_label->setPalette(classe_palette);
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário definir um classificador primeiro!");
        message_box.exec();
    }
}

void MainWindow::dados(ConjuntoDeDados *dados)
{
    if (_dados)
    {
        delete _dados;
    }

    _dados = dados;
}

void MainWindow::carregarArquivo()
{
    QString nome_arquivo = QFileDialog::getOpenFileName(this, tr("Abrir arquivo de dados"), "");

    try {
        dados(new ConjuntoDeDados(nome_arquivo.toStdString()));
        _ui->graphicsView->limpar();
    } catch (exception &e)
    {
        QMessageBox message_box;
        message_box.setText("Não foi possível carregar a base de dados selecionada");
        message_box.exec();
    }
}
