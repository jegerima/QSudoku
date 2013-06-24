#include "celda.h"
#include <QFont>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <string.h>

Celda::Celda(int value) : QFrame(0,0), valor(value)
{
    QVBoxLayout *qv = new QVBoxLayout(this);
    qv->setMargin(0);
    qv->setSpacing(0);

    //Numero Principal
    QFont f1( "Arial", 16, QFont::Bold);
    number = new QLineEdit(QString::number(value));
    number->setFont(f1);
    number->setInputMask("0");//+++++
    number->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    qv->addWidget(number);

    //Numero potencial
    lite_number = new QLabel("5");
    lite_number->setLineWidth(1);
    lite_number->setAlignment(Qt::AlignCenter);
    lite_number->setFrameShape(QFrame::Box);

    //Sugerencias de Numeros
    QFont f3( "Arial", 8);
    hints = new QLabel("2345");
    hints->setFont(f3);
    hints->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    hints->setLineWidth(1);
    hints->setFrameShape(QFrame::Box);

    QGridLayout *grid = new QGridLayout();
    grid->addWidget(hints,0,0,0,3,0);
    grid->addWidget(lite_number,0,3,1,1,0);

    qv->addLayout(grid,0);
    this->setLayout(qv);
    this->setLineWidth(2);
    this->setFrameShape(QFrame::Box);
}

int Celda::getValue()
{
    return (number->text()).toInt();
}

int Celda::getIndex()
{
   return id;
}

int* Celda::getPosibilities()
{
    return posibles;
}

bool Celda::isChecked()
{
    return revisada;
}

bool Celda::hasNum()
{
    return hayNum;
}

void Celda::setValue(int valor)
{
    this->valor = valor;
    this->number->setText(QString::number(valor));
}

void Celda::check()
{
    this->revisada = true;
}

void Celda::unCheck()
{
    this->revisada = false;
}

void Celda::setBackColor(QString color)
{
    number->setStyleSheet("QLineEdit { background-color: " + color + "; }");
}
