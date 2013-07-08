/**
* @file maintable.h
* @brief clase principal del juego
*
* @author Jefferson Rivera
* @author Rúben Carbajal
* @author César Madrid
*
* @date 07/07/2013
*/
#ifndef MAINTABLE_H
#define MAINTABLE_H

#include <QMainWindow>
#include <celda.h>
#include <nivel.h>
#include <QTime>
#include <QTimer>
#include <QPushButton>

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
    void nuevaPartida();
    void guardarPartida();
    void cargarPartida();
    void salirJuego();
    void timeRefresh();
    void getCeldaRunTime();
    void numPressed();
    void acercaDe();
    void on_cmdHint_clicked();

private:

    //Atributos
    int matriz[9][9];
    int tableroActual[9][9];
    int hints;
    int avanceSeg;
    int avanceMin;
    int calcularPuntaje();
    int dificultad;
    nivel *level;
    QString jugador;
    QTimer *tiempo;
    QTime tiempoIni;
    QPushButton *teclado[10];
    QTime *tm;
    Celda *celdaRuntime;
    QStringList pistas;

    //Procedimientos
    void activarTeclado();
    void initGuiCelda();
    void initMenuBar();
    void initCrono();
    void initTeclado();
    void setTableroPrevio();
    void setTableroAGuardar();
    void setTableroAJugar();
    void setIcono();
    void setTableroInicio();
    void setTableroActual();
    void setTableroEnPantalla();
    void setTableroInicialSegunNivel(int n);
    void setCeldasBlanco();
    void setPistas();

    //Funciones
    Ui::MainTable *ui;
    bool checkFila(int row, int column);
    bool checkColumna(int row, int column);
    bool checkCuadro(int row, int column);

};

#endif // MAINTABLE_H
