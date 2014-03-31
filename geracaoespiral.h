#ifndef GERACAOESPIRAL_H
#define GERACAOESPIRAL_H

#include <QDialog>

#include "espiralsimples.h"
#include "espiraldupla.h"

class MainWindow;

namespace Ui {
class GeracaoEspiral;
}

class GeracaoEspiral : public QDialog
{
    Q_OBJECT

public:
    explicit GeracaoEspiral(QWidget *parent = 0);
    ~GeracaoEspiral();

public slots:
    void gerarEspiral();

private:
    Ui::GeracaoEspiral *_ui;

    MainWindow * _main_window;
};

#endif // GERACAOESPIRAL_H
