#include "geracaoaleatorio.h"
#include "ui_geracaoaleatorio.h"
#include "mainwindow.h"

GeracaoAleatorio::GeracaoAleatorio(QWidget *parent, int largura, int altura) :
    QDialog(parent),
    ui(new Ui::GeracaoAleatorio)
{
    ui->setupUi(this);

    _main_window = (MainWindow*) parent;

    _largura = largura;
    _altura = altura;
}

GeracaoAleatorio::~GeracaoAleatorio()
{
    delete ui;
}

void GeracaoAleatorio::gerarConjunto()
{
    int numero_pontos = ui->numero_pontos->text().toInt();
    int min_x = -_largura/2;
    int max_x = _largura/2;
    int min_y = -_altura/2;
    int max_y = _altura/2;
    int classes = ui->numero_classes->value();
    ConjuntoAleatorio * dados = new ConjuntoAleatorio(classes, numero_pontos, min_x, min_y, max_x, max_y);
    _main_window->dados(dados);

    setVisible(false);
}
