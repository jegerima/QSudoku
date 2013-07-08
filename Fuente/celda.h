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
                 * @brief reset
                 */
        void reset();
        void check();
        void unCheck();
        void setBackColor(QString color);
        void setBlackBorder();

        //Funciones
        int getValue();
        int getIndex();
        int* getPosibilities();
        bool isChecked();
        bool hasNum();
        QLabel *getNumber();
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
