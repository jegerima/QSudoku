#ifndef CELDA_H
#define CELDA_H

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFrame>

class Celda : public QFrame
{
    public:
        explicit Celda(int value);

        //Procedimientos
        void setValue(int valor);
        void check();
        void unCheck();
        void setBackColor(QString color);

        //Funciones
        int getValue();
        int getIndex();
        int* getPosibilities();
        bool isChecked();
        bool hasNum();

    private:
        //Atributos
        QLineEdit *number;
        QLabel *lite_number;
        QLabel *hints;

        QFrame *fr_number;
        QFrame *fr_lite_number;
        QFrame *fr_hints;

        int id;
        int valor;
        int posibles[9];
        bool hayNum;
        bool revisada;
};

#endif // CELDA_H
