#include "maintable.h"
#include "ui_maintable.h"
#include "genmatriz.h"
#include <QLineEdit>
#include <QGridLayout>
#include <QApplication>
#include <QString>
#include <QLayoutItem>
#include <QDebug>
#include <QMessageBox>
#include <stdio.h>
#include <QFrame>
#include <iostream>
#include <time.h>       /* time */

MainTable::MainTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainTable)
{
    ui->setupUi(this);
    QMessageBox::information(0,tr("QSudoku Message"),tr("Bienvenido a QSudoku. Version 0.1.20"));

    initGuiCelda();
    srand (time(NULL));

}

MainTable::~MainTable()
{
    delete ui;
}

void MainTable::initGuiCelda()
{
    ui->cmdVerificar->setEnabled(false);
    int k = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            Celda *cas = new Celda(k);
            ui->tablero->addWidget(cas,i,j);
            k++;
        }
    }

    connect(ui->cmdGen, &QPushButton::clicked, this, &MainTable::setTableroPrevio);
}

bool MainTable::checkFila(int row, int column)
{
    for (int i = 0; i < 9; i++){
        if (i != column){
            if (matriz[row][i] == matriz[row][column] )
            {
                qDebug("Error en la fila %d",row+1);
                return false;
            }
        }
    }
    return true;
}

bool MainTable::checkColumna(int row, int column)
{

    for (int i = 0; i < 9; i++){
        if (i != row){
            if (matriz[i][column] == matriz[row][column] )
            {
                qDebug("Error en la columna %d",column+1);
                return false;
            }
        }
    }
    return true;
}

bool MainTable::checkCuadro(int row, int column)
{
    int vsquare = row/3;
    int hsquare = column/3;

    for (int i = vsquare * 3; i < (vsquare*3 + 3); i++)
    {
        for (int j = hsquare * 3; j < (hsquare*3 + 3); j++)
        {
            if (!(i == row && j == column))
            {
                if (matriz[ row ][ column ] == matriz[i][j])
                {
                    qDebug("Error en el cuadro (%d,%d)",row, column);
                    qDebug("(%d == %d) - i,j (%d,%d)",matriz[ row ][ column ], matriz[i][j] , i, j);
                    return false;
                }
            }
        }
    }
    return true;
}


void MainTable::setTableroPrevio()
{
   GenMatriz *matriz = new GenMatriz();
    //int valores[81] = {8,2,4,7,5,3,6,9,1,7,9,1,8,6,4,5,3,2,6,5,3,9,1,2,7,8,4,9,6,2,4,8,7,1,5,3,3,1,8,5,2,9,4,6,7,5,4,7,1,3,6,9,2,8,1,3,6,2,4,5,8,7,9,4,7,5,3,9,8,2,1,6,2,8,9,6,7,1,3,4,5};

    int k = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            ( (Celda*)( ( (QLayoutItem*)ui->tablero->itemAtPosition(i,j) )->widget() ) )->setValue(matriz->arregloDeNumeros(i,j));
            k++;

        }
    }
    ui->cmdVerificar->setEnabled(true);
}


void MainTable::on_cmdVerificar_clicked()
{
    bool t = true;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            QLayoutItem *qli = ui->tablero->itemAtPosition(i,j);
            Celda *qle = (Celda*)(qli->widget());
            QString srt = QString::number(qle->getValue());
            qDebug() << srt;
            matriz[i][j] = srt.toInt();
        }
        qDebug(" ");
    }

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {

            ((Celda*)( ( (QLayoutItem*)ui->tablero->itemAtPosition(i,j) )->widget() ))->setBackColor("white");


            if( !(checkFila(i,j) ) )
            {
                //QMessageBox::warning(0,tr("QSudoku Message"),"Error de fila (" + QString::number(i+1) + "," + QString::number(j+1) + ")");
                ((Celda*)( ( (QLayoutItem*)ui->tablero->itemAtPosition(i,j) )->widget() ))->setBackColor("red"); //pintar casillas erradas de rojo
                t = false;
            }
            if( !(checkColumna(i,j) ) )
            {
                //QMessageBox::warning(0,tr("QSudoku Message"),"Error de Columna (" + QString::number(i+1) + "," + QString::number(j+1) + ")");
                ((Celda*)( ( (QLayoutItem*)ui->tablero->itemAtPosition(i,j) )->widget() ))->setBackColor("red");//pintar casillas erradas de rojo
                t = false;
            }
            if( !(checkCuadro(i,j) ) )
            {
                //QMessageBox::warning(0,tr("QSudoku Message"),"Error de Cuadro (" + QString::number(i+1) + "," + QString::number(j+1) + ")");
                ((Celda*)( ( (QLayoutItem*)ui->tablero->itemAtPosition(i,j) )->widget() ))->setBackColor("red");//pintar casillas erradas de rojo
                t = false;
            }

        }
    }
    if(t == true) //mensaje de confirmacion de que esta correceto
        QMessageBox::warning(0,tr("QSudoku Message"),"Sudoku resuelto correctamente.");

}

