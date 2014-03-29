#ifndef GERACAOALEATORIO_H
#define GERACAOALEATORIO_H

#include <QDialog>

#include "conjuntoaleatorio.h"

class MainWindow;

namespace Ui {
class GeracaoAleatorio;
}

class GeracaoAleatorio : public QDialog
{
    Q_OBJECT

public:
    explicit GeracaoAleatorio(QWidget *parent = 0, int largura = 0, int altura = 0);
    ~GeracaoAleatorio();

public slots:
    void gerarConjunto();

private:
    Ui::GeracaoAleatorio *ui;

    MainWindow * _main_window;

    int _largura;
    int _altura;
};

#endif // GERACAOALEATORIO_H
