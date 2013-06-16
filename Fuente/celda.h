#ifndef CELDA_H
#define CELDA_H

#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <casilla.h>


class Celda : public QFrame
{
    public:
        explicit Celda(int value);

    private:
        //Atributos
        QLabel *number;
        QLabel *lite_number;
        QLabel *hints;

        QFrame *fr_number;
        QFrame *fr_lite_number;
        QFrame *fr_hints;

        Casilla *cas;
};

#endif // CELDA_H
