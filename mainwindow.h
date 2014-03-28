#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "geracaoespiral.h"
#include "espiralsimples.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void desenharPontos(vector<Ponto*> ponto);

public slots:
    void gerarEspiral();
    void classificar();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * viewport;

    GeracaoEspiral * espirais;

    Ponto transformar(Ponto * ponto);

};

#endif // MAINWINDOW_H
