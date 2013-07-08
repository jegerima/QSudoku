/**
* @file genmatriz.h
* @brief En esta clase se encarga de la creacion de las tablas de sudoku
*
* @author Jefferson Rivera
* @author Rúben Carbajal
* @author César Madrid
*
* @date 07/07/2013
*/
#ifndef GENMATRIZ_H
#define GENMATRIZ_H

#include <QPoint>
#include <QList>

class GenMatriz
{
public:
    /**
         * @brief El contructor de la clase GenMatriz, crea un sudoku
         *resuelto a partir de un algoritmo de semilla
         *
         */
    GenMatriz();
    /**
         * @brief La funcion llenarMatrizSemilla es usada internamente en el
         * constructor de la clase para setear un sudoku resuelto
         */
    void llenarMatrizSemilla();
    /**
        * @brief La funcion generarMatrizSudoku se encarga de cambiar numeros, filasy columnas
        *para generar sudokus diferentes
        */
    void generarMatrizSudoku();
    /**
         * @brief La funcion generarArreglos nos permite guardar la posicion de  cada numero de la matriz
         */
    void generarArreglos();
    /**
         * @brief La funcion arregloDeNumeros retorna un valor de una matriz
         * @param i es la posicion del subindice para la fila
         * @param j es la posicion delsubindice para la columna
         * @return retorna un entero con el valor de esa posicion en la matriz
         */
    int arregloDeNumeros(int i, int j);
    /**
         * @brief guardarPosNum mantiene la poscicion de cada numero
         * @param n es el numero
         * @param fila posicion de la fila en la matriz
         * @param columna posicion de la columna de la matriz
         */
    void guardarPosNum(int n, int fila, int columna);
    /**
         * @brief imprimirMatriz imprime una matriz de 9 x 9
         * @param matriz es la matriz a ser impresa
         */
    void imprimirMatriz(int matriz[9][9]);
    /**
         * @brief colocarNumeros ubica los valores en una nueva poscicion
         * @param aleatorios es la nueva poscicion de los numeros
         */
    void colocarNumeros(QList<int> aleatorios);

private:
    /**
         * @brief matrizSeed matriz semilla para iniciar el algoritmo
         */
    int matrizSeed[9][9];
    /**
         * @brief matriz es la matriz resultante final
         */
    int matriz[9][9];
    /**
         * @brief num[1-9] listas de numeros para las posciciones
         */
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
