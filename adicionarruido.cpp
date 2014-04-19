#include "adicionarruido.h"
#include "ui_adicionarruido.h"

#include "mainwindow.h"

AdicionarRuido::AdicionarRuido(QWidget *parent) :
    QDialog(parent),
    _ui(new Ui::AdicionarRuido)
{
    _ui->setupUi(this);

    _main_window = (MainWindow*) parent;
}

AdicionarRuido::~AdicionarRuido()
{
    delete _ui;
}

void AdicionarRuido::adicionarRuido()
{
    int incidencia = _ui->incidencia->value();
    int ruido = _ui->ruido->value();

    _main_window->adicionarRuido(incidencia, ruido);
}
