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

    _ui->view_dados->fixarMainWindow(this);
    _ui->view_treino->fixarMainWindow(this);
    _ui->view_teste->fixarMainWindow(this);

    PaletaDeCores::criarPaleta();

    _dados = 0;
    _classificador = 0;
    _agrupador = 0;
}

MainWindow::~MainWindow()
{
    delete _ui;

    delete _espirais;
    delete _aleatorio;
    delete _ruido;
    delete _remover;
}

void MainWindow::mousePressEvent(float x, float y)
{
    vector<float> coordenadas;
    coordenadas.push_back(x);
    coordenadas.push_back(y);
    Ponto ponto(coordenadas);

    int largura = _ui->view_dados->width();
    int altura = _ui->view_dados->height();
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
                _ui->view_treino->desenharPontos(((IBL*)_classificador)->treino());
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
                _ui->view_treino->desenharPontos(((IBL*)_classificador)->treino());
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
                _ui->view_treino->desenharPontos(((IBL*)_classificador)->treino());
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
                _ui->view_treino->desenharPontos(((IBL*)_classificador)->treino());
            }

            int corretas = ((IBL*)_classificador)->corretas();
            int incorretas = ((IBL*)_classificador)->incorretas();
            _ui->corretas->setText(QString::number(corretas));
            _ui->incorretas->setText(QString::number(incorretas));

            mostrarPesos(((IBL4*)_classificador)->pesos());
        } else if (_ui->ibl5_radio->isChecked())
        {
            _classificador = new IBL5(distancia, _dados->classes(), _dados->dimensoes());
            ((IBL*)_classificador)->treinar(_dados);
            if (_dados->dimensoes()==2)
            {
                _ui->view_treino->desenharPontos(((IBL*)_classificador)->treino());
            }

            int corretas = ((IBL*)_classificador)->corretas();
            int incorretas = ((IBL*)_classificador)->incorretas();
            _ui->corretas->setText(QString::number(corretas));
            _ui->incorretas->setText(QString::number(incorretas));

            mostrarPesos(((IBL4*)_classificador)->pesos());
        }
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário carregar um conjunto de dados primeiro!");
        message_box.exec();
    }
}

void MainWindow::definirAgrupamento()
{
    if (_dados)
    {
        if (_agrupador)
        {
            delete _agrupador;
        }
        if (_ui->arvore_radio->isChecked())
        {

        } else
        if (_ui->kmeans_radio->isChecked())
        {
            int k = _ui->kmeans_k->value();
            _agrupador = new KMeans(k);
            _dados->classes(k);
        }
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário carregar um conjunto de dados primeiro!");
        message_box.exec();
    }
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

void MainWindow::testarPontos()
{
    _ui->view_teste->limpar();
    if (_dados && _dados->dimensoes() == 2 && _classificador)
    {
        int distancia_pontos = _ui->distancia_pontos->value();
        int width = _ui->view_teste->width();
        int height = _ui->view_teste->height();
        for (int x = -width/2; x < width/2; x += distancia_pontos)
        {
            for (int y = -height/2; y < height/2; y += distancia_pontos)
            {
                vector<float> atributos;
                atributos.push_back(x);
                atributos.push_back(y);

                Ponto * ponto = new Ponto(atributos);
                int classe = _classificador->classificar(ponto);
                delete ponto;
                ponto = new Ponto(atributos, classe);
                _ui->view_teste->desenharPonto(*ponto);
                delete ponto;
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

void MainWindow::agrupar()
{
    if (_agrupador)
    {
        _agrupador->agrupar(_dados);
        _ui->view_dados->desenharPontos(_dados->pontos());
    } else
    {
        QMessageBox message_box;
        message_box.setText("É necessário definir um agrupador primeiro!");
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

void MainWindow::carregarArquivo()
{
    QString nome_arquivo = QFileDialog::getOpenFileName(this, tr("Abrir arquivo de dados"), "");

    try {
        _ui->view_dados->limpar();
        _ui->view_treino->limpar();
        _ui->view_teste->limpar();

        dados(new ConjuntoDeDados(nome_arquivo.toStdString()));
    } catch (exception &e)
    {
        QMessageBox message_box;
        message_box.setText("Não foi possível carregar a base de dados selecionada");
        message_box.exec();
    }
}
