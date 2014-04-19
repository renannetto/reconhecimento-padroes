#ifndef ADICIONARRUIDO_H
#define ADICIONARRUIDO_H

#include <QDialog>

class MainWindow;

namespace Ui {
class AdicionarRuido;
}

class AdicionarRuido : public QDialog
{
    Q_OBJECT

public:
    explicit AdicionarRuido(QWidget *parent = 0);
    ~AdicionarRuido();

public slots:
    void adicionarRuido();

private:
    Ui::AdicionarRuido *_ui;

    MainWindow * _main_window;
};

#endif // ADICIONARRUIDO_H
