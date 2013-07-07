#ifndef GUARDAR_H
#define GUARDAR_H
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QTime>

class Guardar
{
public:
    Guardar();
    void crearArchivo();
    void guardarValores(int m[9][9], int sol[9][9], QString jugador, QString nivel, QString tiempo);
    void leerArchivo(int m[9][9], int sol[9][9], QString *name, QString *level, QTime *t);

private:
    QString cadenaAGuardar;
    int valores[81];
    int matriz[9][9];
};

#endif // GUARDAR_H
