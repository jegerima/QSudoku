#ifndef MAINTABLE_H
#define MAINTABLE_H

#include <QMainWindow>
#include <celda.h>
#include <nivel.h>

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
    void iniciarJuego(int n);
    void on_cmdVerificar_clicked();
    void guardarPartida();
    void cargarPartida();
    void salirJuego();

private:

    //Atributos
    int matriz[9][9];
    int tableroActual[9][9];
    nivel *level;

    //Procedimientos
    void initGuiCelda();
    void initMenuBar();
    void setTableroInicio();
    void setTableroActual();
    void setTableroEnPantalla();
    void setTableroInicialSegunNivel(int n);


    //Funciones
    Ui::MainTable *ui;
    bool checkFila(int row, int column);
    bool checkColumna(int row, int column);
    bool checkCuadro(int row, int column);

};

#endif // MAINTABLE_H
