#include "casilla.h"

Casilla::Casilla(int index, int value): QLineEdit(QString::number(value)), id(index), hayNum(false), revisada(false)
{

}

Casilla::Casilla(int value): QLineEdit(QString::number(value)), id(0), hayNum(false), revisada(false)
{

}

int Casilla::getValue()
{
    return valor;
}

int Casilla::getIndex()
{
   return id;
}

int* Casilla::getPosibilities()
{
    return posibles;
}

bool Casilla::isChecked()
{
    return revisada;
}

bool Casilla::hasNum()
{
    return hayNum;
}

void Casilla::setValue(int valor)
{
    this->valor = valor;
}

void Casilla::check()
{
    this->revisada = true;
}

void Casilla::unCheck()
{
    this->revisada = false;
}





