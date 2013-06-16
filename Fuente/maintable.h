#ifndef MAINTABLE_H
#define MAINTABLE_H

#include <QMainWindow>
#include <casilla.h>

namespace Ui {
class MainTable;
}

class QLineEdit;
class QGridLayout;

class MainTable : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainTable(QWidget *parent = 0);
    ~MainTable();
    
private slots:
    void verify_clicked();

private:

    //Atributos
    int matriz[9][9];

    //Procedimientos
    void initGui();
    void initGuiCelda();
    void setTableroPrevio();
    void initGridCasilla();

    //Funciones
    Ui::MainTable *ui;
    //QLineEdit *numberField[81];
    bool checkFila(int row, int column);
    bool checkColumna(int row, int column);
    bool checkCuadro(int row, int column);

};

#endif // MAINTABLE_H
