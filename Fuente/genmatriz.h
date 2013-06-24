#ifndef GENMATRIZ_H
#define GENMATRIZ_H

#include <QPoint>
#include <QList>

class GenMatriz
{
public:
    GenMatriz();
    void llenarMatrizSemilla();
    void generarMatrizSudoku();
    void generarArreglos();
    int arregloDeNumeros(int i, int j);
    void guardarPosNum(int n, int fila, int columna);
    void imprimirMatriz(int matriz[9][9]);
    void colocarNumeros(QList<int> aleatorios);

private:
    int matrizSeed[9][9];
    int matriz[9][9];
    QList<QPoint> num1;
    QList<QPoint> num2;
    QList<QPoint> num3;
    QList<QPoint> num4;
    QList<QPoint> num5;
    QList<QPoint> num6;
    QList<QPoint> num7;
    QList<QPoint> num8;
    QList<QPoint> num9;
};

#endif // GENMATRIZ_H
