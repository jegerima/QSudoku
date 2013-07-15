/**
* @file guardar.h
* @brief en esta clase se lleva a cargo el guardado de las tablas
*
* @author Jefferson Rivera
* @author Rúben Carbajal
* @author César Madrid
*
* @date 07/07/2013
*/
#ifndef GUARDAR_H
#define GUARDAR_H
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QTime>

/**
 * @brief The Guardar Es la clase encargada de guardar y cargar archivos
 */
class Guardar
{
public:
    /**
         * @brief Guardar constructor de la clase guardar para guardar y leer archivos encriptados
         */
    Guardar();
    /**
         * @brief crearArchivo abre la ventana default del sistema para explorar archivos y obtener la ruta
         */
    void crearArchivo();
    /**
     * @brief guardarValores concatena todos los datos a ser guardados
     * @param m matriz que mantiene el avance del juego
     * @param sol matriz con la solucion del juego
     * @param jugador nombre del juagador
     * @param nivel nivel en el que esta jugando
     * @param tiempo tiempo acumulado del reloj
     */
    void guardarValores(int m[9][9], int sol[9][9], QString jugador, QString nivel, QString tiempo,int inicio[9][9],int hints);
    /**
     * @brief leerArchivo lee el archivo y usa una expresion regular para separar las distintas candenas
     * @param m setea en esta el avance del juego
     * @param sol setea en sol la solucion del juego
     * @param name para setear el nombre del jugador
     * @param level para setear el nivel del jugador
     * @param t para setear el tiempo del juegador
     */
    void leerArchivo(int m[9][9], int sol[9][9], QString *name, QString *level, QTime *t,int inicio [9][9],int *hint);

private:
    /**
     * @brief cadenaAGuardar String con la cadena completa de datos a ser guardada
     */
    QString cadenaAGuardar;
    /**
     * @brief valores arreglo unidimensinal de 81 valores
     */
    int valores[81];
    /**
     * @brief matriz con los datos de alguna matriz de 9x9 para manejo interno de la clase
     */
    int matriz[9][9];
};

#endif // GUARDAR_H
