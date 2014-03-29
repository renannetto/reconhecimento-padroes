#include "geracaoespiral.h"
#include "ui_geracaoespiral.h"

#include "mainwindow.h"

GeracaoEspiral::GeracaoEspiral(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeracaoEspiral)
{
    ui->setupUi(this);

    main_window = (MainWindow*)parent;
}

GeracaoEspiral::~GeracaoEspiral()
{
    delete ui;
}

void GeracaoEspiral::gerarEspiral()
{
    int numero_pontos = ui->pontos_edit->text().toInt();
    EspiralSimples * espiral = new EspiralSimples(numero_pontos);
    main_window->desenharPontos(espiral->pontos());

    setVisible(false);

    delete espiral;
}
