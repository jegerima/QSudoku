#include "nivel.h"
#include "ui_nivel.h"
#include <QPushButton>
#include <string.h>
#include <QDebug>

nivel::nivel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nivel)
{
    ui->setupUi(this);
    initGui();
}

void nivel::initGui()
{
    levels[0] = new QPushButton(QString("Novato"));
    levels[1] = new QPushButton(QString("Intermedio"));
    levels[2] = new QPushButton(QString("Profesional"));
    levels[3] = new QPushButton(QString("Leyenda"));

    for(int i = 0; i <4; i++)
    {
        connect(levels[i],&QPushButton::clicked, this, &nivel::emitirNivel);
        ui->lyLevel->addWidget(levels[i]);
    }
}

void nivel::emitirNivel()
{
    QPushButton *cmd = (QPushButton*)sender();
    if(cmd->text()=="Novato")
    {
        emit appReady(0);
        qDebug("Novato");
    }
    if(cmd->text()=="Intermedio")
    {
        emit appReady(1);
        qDebug("Intermedio");
    }
    if(cmd->text()=="Profesional")
    {
        emit appReady(2);
        qDebug("Profesional");
    }
    if(cmd->text()=="Leyenda")
    {
        emit appReady(3);
        qDebug("Leyenda");
    }
}

nivel::~nivel()
{
    delete ui;
}
