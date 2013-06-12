#include "maintable.h"
#include "ui_maintable.h"
#include <QLineEdit>
#include <QGridLayout>
#include <QApplication>
#include <QString>
#include <QLayoutItem>
#include <QDebug>
#include <stdio.h>

MainTable::MainTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainTable)
{
    ui->setupUi(this);
    initGui();
}

MainTable::~MainTable()
{
    delete ui;
}

void MainTable::initGui()
{
    int k = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            //numberField[k] = new QLineEdit(QString::number(k),0);
            //ui->tablero->addWidget(numberField[k],i,j);
            Casilla *cas = new Casilla(k, 0);
            ui->tablero->addWidget(cas,i,j);
            k++;
        }
    }

    connect(ui->cmdVerificar, &QPushButton::clicked, this, &MainTable::verify_clicked);
    connect(ui->cmdGen, &QPushButton::clicked, this, &MainTable::setTableroPrevio);
}

void MainTable::verify_clicked()
{
    //int k = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            QLayoutItem *qli = ui->tablero->itemAtPosition(i,j);
            QLineEdit *qle = (QLineEdit*)(qli->widget());
            QString srt = qle->text();
            qDebug() << srt;
            matriz[i][j] = srt.toInt();

            if( !(checkFila(i,j) ) )
            {
                //return;
            }
            if( !(checkColumna(i,j) ) )
            {
                //return;
            }
            if( !(checkCuadro(i,j) ) )
            {
                //return;
            }

        }
    }
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
    qDebug("Fila Correcta");
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
    qDebug("Columna Correcta");
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
                    qDebug("Error en el cuadro (%d,%d)",row+1, column+1);
                    return false;
                }
            }
        }
    }
    qDebug("Cuadro Correcto");
    return true;
}

void MainTable::setTableroPrevio()
{
    int valores[81] = {8,2,4,7,5,3,6,9,1,7,9,1,8,6,4,5,3,2,6,5,3,9,1,2,7,8,4,9,6,2,4,8,7,1,5,3,3,1,8,5,2,9,4,6,7,5,4,7,1,3,6,9,2,8,1,3,6,2,4,5,8,7,9,4,7,5,3,9,8,2,1,6,2,8,9,6,7,1,3,4,5};
    /*
    int valores[9][9];
    valores[0] = {8,2,4,7,5,3,6,9,1};
    valores[1] = {7,9,1,8,6,4,5,3,2};
    valores[2] = {6,5,3,9,1,2,7,8,4};
    valores[3] = {9,6,2,4,8,7,1,5,3};
    valores[4] = {3,1,8,5,2,9,4,6,7};
    valores[5] = {5,4,7,1,3,6,9,2,8};
    valores[6] = {1,3,6,2,4,5,8,7,9};
    valores[7] = {4,7,5,3,9,8,2,1,6};
    valores[8] = {2,8,9,6,7,1,3,4,5};
    */


    int k = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            ( (Casilla*)( ( (QLayoutItem*)ui->tablero->itemAtPosition(i,j) )->widget() ) )->setText(QString::number(valores[k]));
            k++;
        }
    }
}
