#ifndef CELDA_H
#define CELDA_H

#include <QVBoxLayout>
#include <QLabel>
#include <QPalette>
#include <QFrame>

class Celda : public QFrame
{
    Q_OBJECT

    public:
        explicit Celda(int value);

        //Procedimientos
        void setValue(int valor);
        void addHint(int valor);
        void setLite(int valor);
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
