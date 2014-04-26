#ifndef REMOVERATRIBUTOS_H
#define REMOVERATRIBUTOS_H

#include <QDialog>

class MainWindow;

namespace Ui {
class RemoverAtributos;
}

class RemoverAtributos : public QDialog
{
    Q_OBJECT

public:
    explicit RemoverAtributos(QWidget *parent = 0);
    ~RemoverAtributos();

public slots:
    void removerAtributos();

private:
    Ui::RemoverAtributos *_ui;

    MainWindow * _main_window;
};

#endif // REMOVERATRIBUTOS_H
