/**
* @file nivel.h
* @brief Clase encargado de emitir señales segun el nivel de dificultad de tablero
* @author Jefferson Rivera
* @author Rúben Carbajal
* @author César Madrid
*
* @date 07/07/2013
*/
#ifndef NIVEL_H
#define NIVEL_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class nivel;
}

/**
 * @brief The nivel esta clase s para emitir diferentes señales segun el nivel de dificultad que el usuario elija
 */
class nivel : public QDialog
{
    Q_OBJECT
    
public:
    explicit nivel(QWidget *parent = 0);
    ~nivel();

signals:
    /**
     * @brief appReady registra el slot que emitio la señal
     * @param parametro de entrada de la señal
     */
    void appReady(int i);

private:
    Ui::nivel *ui;

    //Procedimientos
    /**
     * @brief initGui inicializa la gui de escoger niveles
     */
    void initGui();
    /**
     * @brief emitirNivel emite una señal de 0, 1, 2 o 3 segun el nivel seleccionado
     */
    void emitirNivel();
    /**
     * @brief setImagen setea el logo del programa
     */
    void setImagen();

    //Atributos
    QPushButton *levels[4];


};

#endif // NIVEL_H
