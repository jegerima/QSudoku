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

class Guardar
{
public:
    /**
         * @brief Guardar constructor de la clase guardar para guardar y leer archivos encriptados
         */
    Guardar();
    /**
         * @brief crearArchivo abre la ventana default del sistema para explorar archivos
         */
    void crearArchivo();
    void guardarValores(int m[9][9], int sol[9][9], QString jugador, QString nivel, QString tiempo);
    void leerArchivo(int m[9][9], int sol[9][9], QString *name, QString *level, QTime *t);

private:
    QString cadenaAGuardar;
    int valores[81];
    int matriz[9][9];
};

#endif // GUARDAR_H
