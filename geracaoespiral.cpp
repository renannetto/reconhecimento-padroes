#include "geracaoespiral.h"
#include "ui_geracaoespiral.h"

#include "mainwindow.h"

GeracaoEspiral::GeracaoEspiral(QWidget *parent) :
    QDialog(parent),
    _ui(new Ui::GeracaoEspiral)
{
    _ui->setupUi(this);

    _main_window = (MainWindow*)parent;
}

GeracaoEspiral::~GeracaoEspiral()
{
    delete _ui;
}

void GeracaoEspiral::gerarEspiral()
{
    int numero_pontos = _ui->numero_pontos->text().toInt();
    float a = _ui->rotacao->text().toFloat();
    float b = _ui->distancia->text().toFloat();
    float passo = _ui->passo->text().toFloat();
    int ruido = _ui->ruido->value();

    if (_ui->espiral_simples_radio->isChecked())
    {
        EspiralSimples * espiral = new EspiralSimples(numero_pontos, a, b, passo, ruido);
        _main_window->desenharPontos(espiral->pontos());
        _main_window->dados(espiral);
    } else
    {
        EspiralDupla * espiral = new EspiralDupla(numero_pontos, a, b, passo, ruido);
        _main_window->desenharPontos(espiral->pontos());
        _main_window->dados(espiral);
    }

    setVisible(false);
}
