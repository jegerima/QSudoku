#include "celda.h"
#include <QFont>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <QString>
#include <string.h>

Celda::Celda(int value, QPoint poscicion) : QFrame(0,0), valor(value), pos(poscicion)
{
    QVBoxLayout *qv = new QVBoxLayout(this);
    qv->setMargin(0);
    qv->setSpacing(0);

    //Numero Principal
    QFont f1( "Arial", 16, QFont::Bold);
    number = new QLabel(QString::number(value));
    number->setFont(f1);

    //number->setInputMask("0");
    number->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    qv->addWidget(number);

    //Numero potencial
    lite_number = new QLabel("");
    lite_number->setLineWidth(1);
    lite_number->setAlignment(Qt::AlignCenter);
    lite_number->setFrameShape(QFrame::Box);

    //Sugerencias de Numeros
    QFont f3( "Arial", 8);
    hints = new QLabel("");
    hints->setFont(f3);
    hints->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    hints->setLineWidth(1);
    hints->setFrameShape(QFrame::Box);

    //Opciones del Frame
    QGridLayout *grid = new QGridLayout();
    grid->addWidget(hints,0,0,0,3,0);
    grid->addWidget(lite_number,0,3,1,1,0);
    qv->addLayout(grid,0);
    this->setLayout(qv);
    this->setLineWidth(2);
    this->setFrameShape(QFrame::Box);
    this->paleta = new QPalette();
    paleta->setColor(QPalette::Foreground,Qt::black);
    this->setPalette(*paleta);
    //qDebug() << pos;
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
    if(valor==0)
    {
        this->valor=valor;
        this->number->setText(" ");
    }
    else
    {
        this->valor = valor;
        paleta->setColor(QPalette::Foreground,Qt::black);
        this->setPalette(*paleta);
        this->number->setText(QString::number(valor));
    }
    //number->setText("<font color='Black'>"+ QString::number(valor)+"</font>");
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
    number->setStyleSheet("QLabel { background-color: " + color + "; }");
}

void Celda::addHint(int valor)
{
    int tmp = (hints->text()).toInt();
    hints->setText(QString::number(tmp*10+valor));
}

void Celda::setLite(int valor)
{
    lite_number->setText(QString::number(valor));
}

void Celda::reset()
{
    //number->setText("0");
    lite_number->setText("");
    hints->setText("");
}

QLabel *Celda::getNumber()
{
    return number;
}

void Celda::setEmpty()
{
    paleta->setColor(QPalette::Foreground,Qt::blue);
    this->setPalette(*paleta);
    this->setBackColor("white");
}

void Celda::mouseReleaseEvent(QMouseEvent *)
{
    emit clicked();
}

void Celda::setBlackBorder()
{
    paleta->setColor(QPalette::Foreground,Qt::black);
    this->setPalette(*paleta);
}
