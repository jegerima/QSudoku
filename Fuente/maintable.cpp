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
    QMessageBox::information(0,tr("QSudoku Message"),tr("Bienvenido a QSudoku. Version 0.1.31"));

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
    ui->tablero->setHorizontalSpacing(8);
    ui->tablero->setVerticalSpacing(8);
    int k = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            QGridLayout *cuadro = new QGridLayout();
            cuadro->setHorizontalSpacing(1);
            cuadro->setVerticalSpacing(1);
            for(int l = 0; l < 3; l++)
            {
                for(int m = 0; m < 3; m++)
                {
                    Celda *cas = new Celda(((j*3)+m+(i*27)+(l*9)));
                    cuadro->addWidget(cas,l,m);
                    k++;
                }
            }
            ui->tablero->addLayout(cuadro,i,j);
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

            ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->setValue(matriz->arregloDeNumeros(i,j));
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
        for(int j = 0; j <9; j++)
        {
                    QLayoutItem *qli = ((QGridLayout*)(ui->tablero->itemAtPosition(i/3,j/3)))->itemAtPosition(i%3,j%3);
                    Celda *qle = (Celda*)(qli->widget());
                    QString srt = QString::number(qle->getValue());
                    qDebug() << srt;
                    matriz[(i)][(j)] = srt.toInt();

        }
        qDebug(" ");
    }
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {

            ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->setBackColor("white");


            if( !(checkFila(i,j) ) )
            {
                //QMessageBox::warning(0,tr("QSudoku Message"),"Error de fila (" + QString::number(i+1) + "," + QString::number(j+1) + ")");
                ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->setBackColor("red"); //pintar casillas erradas de rojo
                t = false;
            }
            if( !(checkColumna(i,j) ) )
            {
                //QMessageBox::warning(0,tr("QSudoku Message"),"Error de Columna (" + QString::number(i+1) + "," + QString::number(j+1) + ")");
                ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->setBackColor("red");//pintar casillas erradas de rojo
                t = false;
            }
            if( !(checkCuadro(i,j) ) )
            {
                //QMessageBox::warning(0,tr("QSudoku Message"),"Error de Cuadro (" + QString::number(i+1) + "," + QString::number(j+1) + ")");
                ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->setBackColor("red");//pintar casillas erradas de rojo
                t = false;
            }

        }
    }
    if(t == true) //mensaje de confirmacion de que esta correceto
        QMessageBox::warning(0,tr("QSudoku Message"),"Sudoku resuelto correctamente.");
    else
        QMessageBox::warning(0,tr("QSudoku Message"),"El sudoku se encuentra incorrecto.");

}

