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
/**
 * @brief The MainTable Es la clase principal que matiene el tablero la gui
 */

class MainTable : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainTable(QWidget *parent = 0);
    ~MainTable();
    
private slots:
    /**
     * @brief iniciarJuego arranca el juego, seteando todas sus caracteristicas
     * @param n nivel en elque esta jugando
     */
    void iniciarJuego(int n);
    /**
     * @brief on_cmdVerificar_clicked slot del boton verificar, para chequear correcta resolucion del sudoku
     */
    void on_cmdVerificar_clicked();
    /**
     * @brief nuevaPartida setea valores previos antes de iniciar el juego
     */
    void nuevaPartida();
    /**
     * @brief guardarPartida llama a la clase guardar para generar un archivo externo con todos los datos
     *  actuales del juego
     */
    void guardarPartida();
    /**
     * @brief cargarPartida llama a la clase Guardar para setear valores desde un archivo y empezar una partida
     */
    void cargarPartida();
    /**
     * @brief salirJuego muestra mensaje de salida puntaje final al que llego
     */
    void salirJuego();
    /**
     * @brief timeRefresh slot del reloj para actualizar tiempo cada 1000 ms
     */
    void timeRefresh();
    /**
     * @brief getCeldaRunTime obtiene la celda clicleada en ese instante
     */
    void getCeldaRunTime();
    /**
     * @brief numPressed slot para verificar numero presionado en el teclado numerico
     */
    void numPressed();
    /**
     * @brief acercaDe muestra opciones en el menu Acerca de
     */
    void acercaDe();
    /**
     * @brief on_cmdHint_clicked slot para el boton Hint, permite despejar una casilla
     */
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
    /**
     * @brief activarTeclado desbloquea el teclado numerico, para que pueda ser presionado
     */
    void activarTeclado();
    /**
     * @brief initGuiCelda inicializa todos los componentes de la GUI
     */
    void initGuiCelda();
    /**
     * @brief initMenuBar inicializa los componentes de la barra de menu
     */
    void initMenuBar();
    /**
     * @brief initCrono pone a correr el cronometro desde 0
     */
    void initCrono();
    /**
     * @brief initTeclado inicializa el teclado numerico dinamicamente
     */
    void initTeclado();

    void setIcono();
    /**
     * @brief setTableroInicio setea la solucion de un sudoku usando la clase genMAtriz
     */
    void setTableroInicio();
    /**
     * @brief setTableroActual setea el avance del tablero jugado
     */
    void setTableroActual();
    /**
     * @brief setTableroEnPantalla muestra en pantalla la matriz de juego Actual
     */
    void setTableroEnPantalla();
    /**
     * @brief setTableroInicialSegunNivel setea el inicio de un juego de acuerdo a un nivel
     * @param n nivel del juego
     */
    void setTableroInicialSegunNivel(int n);
    /**
     * @brief setCeldasBlanco setea un fondo blanco para las celdas
     */
    void setCeldasBlanco();
    /**
     * @brief setPistas verifica el tablero y aigna que pistas se van a mostrar
     */
    void setPistas();

    //Funciones
    Ui::MainTable *ui;
    /**
     * @brief checkFila verifica que las casillas cumplan con las reglas del sudoku en la fila
     * @param row es la fila donde va a verificar
     * @param column es el de la casilla con el que va a verificar
     * @return
     */
    bool checkFila(int row, int column);
    /**
     * @brief checkColumna verifica que las casillas cumplan con las reglas del sudoku en la columna
     * @param row es el de la casilla con el que va a verificar
     * @param column es la columna donde va a verificar
     * @return
     */
    bool checkColumna(int row, int column);
    /**
     * @brief checkCuadro verifica que las casillas cumplan con las reglas del sudoku en el subcuadro
     * @param row es la fila donde va a verificar
     * @param column es la columna donde va a verificar
     * @return
     */
    bool checkCuadro(int row, int column);

};

#endif // MAINTABLE_H
