/**
* @file celda.h
* @brief En esta clase se crean las celdas del sudoku
*
* @author Jefferson Rivera
* @author Rúben Carbajal
* @author César Madrid
*
* @date 07/07/2013
*/
#ifndef CELDA_H
#define CELDA_H

#include <QVBoxLayout>
#include <QLabel>
#include <QPalette>
#include <QFrame>
#include <QPoint>

/**
 * @brief The Celda en esta clase se lleva a cargo la interface de las celdas de nuestro tablero de sudoku
 */
class Celda : public QFrame
{
    Q_OBJECT

    public:
    /**
             * @brief Crea una nueva celda en una posicion con un valor en ella
             * @param el valor de la casilla
             * @param posicion en el tablero del sudoku
             */
        explicit Celda(int value, QPoint poscicion);

        //Procedimientos
    /**
             * @brief cambia el valor de una celda
             * @param valor a colocar en la celda que se cambiara
             */
        void setValue(int valor);
        /**
                 * @brief añade los hints al tablero
                 * @param numero de hints que seran añadidos
                 */
        void addHint(int valor);
        /**
                 * @brief setLite
                 * @param valor
                 */
        void setLite(int valor);
        /**
          * @brief reset setea los valores de la celda a vacio
         */
        void reset();
        /**
         * @brief check muestra la casilla chequeada de otro color
         */
        void check();
        /**
         * @brief unCheck vulve a poner a la casilla a su estado normal
         */
        void unCheck();
        /**
         * @brief setBackColor setea un fondo para la celda
         * @param color de fondo
         */
        void setBackColor(QString color);
        /**
         * @brief setBlackBorder setea un borde a la celda
         */
        void setBlackBorder();

        //Funciones
        /**
         * @brief getValue devuleve el valor dela celda
         * @return retorna un int con el valor
         */
        int getValue();
        /**
         * @brief getIndex retorna el indicepara la celda
         * @return int con el indice
         */
        int getIndex();
        /**
         * @brief getPosibilities
         * @return
         */
        int* getPosibilities();
        /**
         * @brief isChecked verifica si la celda esta chequeada o marcada
         * @return verdadero o falso segun sea el caso
         */
        bool isChecked();
        /**
         * @brief hasNum verifica si hay algun numero en la celda
         * @return  verdadero o falso segun sea el caso
         */
        bool hasNum();
        /**
         * @brief getNumber extrae label de la celda con el numero
         * @return Label principal de la celda
         */
        QLabel *getNumber();
        /**
         * @brief pos poscicion de la celda en referencia a una matriz
         */
        QPoint pos;

    signals:
        void clicked();

    private slots:
        void setEmpty();

    private:
        //Atributos
        QLabel *number;
        QLabel *lite_number;
        QLabel *hints;
        QPalette *paleta;


        int id;
        int valor;
        int lite;
        int posibles[9];
        bool hayNum;
        bool revisada;

    protected:
        void mouseReleaseEvent(QMouseEvent *);
};

#endif // CELDA_H
