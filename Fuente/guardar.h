#ifndef GUARDAR_H
#define GUARDAR_H
#include <QTextStream>
#include <QFile>
#include <QString>

class Guardar
{
public:
    Guardar();
    void crearArchivo();
    void guardarValores(int m[9][9], int sol[9][9]);
    void leerArchivo(int m[9][9], int sol[9][9]);

private:
    void cargarValores(int m[9][9]);
    QString cadenaAGuardar;
    int valores[81];
    int matriz[9][9];
};

#endif // GUARDAR_H
