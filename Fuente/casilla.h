#ifndef CASILLA_H
#define CASILLA_H

#include <QLineEdit>
#include <QString>

class Casilla : public QLineEdit
{
    public:
        Casilla(int index, int value);

    private:
        //Atributos
        int id;
        int valor;
        int posibles[9];
        bool hayNum;
        bool revisada;

        //Procedimientos
        void setValue(int valor);
        void check();
        void unCheck();

        //Funciones
        int getValue();
        int getIndex();
        int* getPosibilities();
        bool isChecked();
        bool hasNum();
};

#endif // CASILLA_H
