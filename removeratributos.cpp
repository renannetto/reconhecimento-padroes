#include "removeratributos.h"
#include "ui_removeratributos.h"

#include "mainwindow.h"

RemoverAtributos::RemoverAtributos(QWidget *parent) :
    QDialog(parent),
    _ui(new Ui::RemoverAtributos)
{
    _ui->setupUi(this);

    _main_window = (MainWindow*) parent;
}

RemoverAtributos::~RemoverAtributos()
{
    delete _ui;
}

void RemoverAtributos::removerAtributos()
{
    int probabilidade = _ui->probabilidade_remocao->value();
    _main_window->removerAtributos(probabilidade);

    setVisible(false);
}
