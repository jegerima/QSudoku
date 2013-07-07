#include "maintable.h"
#include "ui_maintable.h"
#include "genmatriz.h"
#include "guardar.h"
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
    QMessageBox::information(0,tr("QSudoku Message"),tr("Bienvenido a QSudoku. Version 0.1.80"));
    initGuiCelda();
    initMenuBar();
    srand (time(NULL));

}

MainTable::~MainTable()
{
    delete ui;
}

void MainTable::initGuiCelda()
{
    //Formulario de Niveles
    level = new nivel(0);
    level->show();

    //Matriz del Sudoku
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
                    Celda *cas = new Celda(NULL);
                    cuadro->addWidget(cas,l,m);
                    k++;
                }
            }
            ui->tablero->addLayout(cuadro,i,j);
        }
    }

    //Boton para configurar un tablero previo
    //connect(ui->cmdGen, &QPushButton::clicked, this, &MainTable::setTableroInicio);
    connect(level, SIGNAL(appReady(int)), this, SLOT(iniciarJuego(int)));
}

void MainTable::initMenuBar()
{
    connect(ui->actionCargar,SIGNAL(triggered()), this, SLOT(cargarPartida()));
    connect(ui->actionGuardar,SIGNAL(triggered()), this, SLOT(guardarPartida()));
    connect(ui->actionSalir,SIGNAL(triggered()), this, SLOT(salirJuego()));
}

bool MainTable::checkFila(int row, int column)
{
    for (int i = 0; i < 9; i++){
        if (i != column){
            if (tableroActual[row][i] == tableroActual[row][column] )
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
            if (tableroActual[i][column] == tableroActual[row][column] )
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
                if (tableroActual[ row ][ column ] == tableroActual[i][j])
                {
                    qDebug("Error en el cuadro (%d,%d)",row, column);
                    qDebug("(%d == %d) - i,j (%d,%d)",tableroActual[ row ][ column ], tableroActual[i][j] , i, j);
                    return false;
                }
            }
        }
    }
    return true;
}


void MainTable::setTableroInicio()
{
   //genera una nueva solucion de tablero para comenzar todo
   GenMatriz *matrizSolucion = new GenMatriz();
    int k = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            //copio la nueva solucion para el juego en matriz
            matriz[i][j] = matrizSolucion->arregloDeNumeros(i,j);
            //seteo todo a 0 en tablero actual
            tableroActual[i][j] =0;
        }

    }
    ui->cmdVerificar->setEnabled(true);
    //setTableroAJugar();
}



//funcion para guardar el tablero en el momento actual del juego
void MainTable::setTableroActual()
{
    int tmp=0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            //obtengo los valores que estan en el juego actualmente
            tmp = ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))
             ->itemAtPosition(i%3,j%3))->widget()))->getValue();
            //si la celda tiene un numero
            if(tmp!=NULL){
                tableroActual[i][j] = tmp;
                qDebug() << tmp;
            }else{
                tableroActual[i][j] = 0;
            }

        }

    }
}



//setea en pantalla lo que ve el jugador final
void MainTable::setTableroEnPantalla()
{
     int k = 0, tmp=0;
     for(int i = 0; i < 9; i++)
     {
         for(int j = 0; j < 9; j++)
         {
             //muestro en pantalla solo las casillas que no contengan cero
             tmp = tableroActual[i][j];
             if(tmp!=0){
             ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))
                        ->itemAtPosition(i%3,j%3))->widget()))->setValue(tmp);
             }else{
                 ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))
                            ->itemAtPosition(i%3,j%3))->widget()))->setValue(0);
             }
             k++;
         }

     }
     ui->cmdVerificar->setEnabled(true);
}

void MainTable::setTableroInicialSegunNivel(int n)
{
    int fila=0, col=0;

    if(n==0){
        qDebug("Seteando nivel 1");
        for(int i=0; i<51; i++){
            qDebug()<<"entro al for";
            fila = 1+rand()%8;
            col = 1+rand()%8;
            tableroActual[fila][col] = matriz[fila][col];
        }
    }
    if(n==1){
        qDebug("Seteando nivel 2");
        for(int i=0; i<43; i++){
            fila = 1+rand()%8;
            col = 1+rand()%8;
            tableroActual[fila][col] = matriz[fila][col];
        }
    }
    if(n==2){
        qDebug("Seteando nivel 3");
        for(int i=0; i<35; i++){
            fila = 1+rand()%8;
            col = 1+rand()%8;
             tableroActual[fila][col] = matriz[fila][col];
        }
    }
    if(n==3){
        qDebug("Seteando nivel Dios");
        for(int i=0; i<27; i++){
            fila = 1+rand()%8;
            col = 1+rand()%8;
             tableroActual[fila][col] = matriz[fila][col];
        }
    }
}

void MainTable::iniciarJuego(int n)
{
    setTableroInicio();
    setTableroInicialSegunNivel(n);
    setTableroEnPantalla();
    level->hide();
    this->show();
    qDebug("%d",n);

}

void MainTable::salirJuego()
{
    QApplication::quit();
}

void MainTable::on_cmdVerificar_clicked()
{
    bool t = true;
    setTableroActual();

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


void MainTable::guardarPartida()
{
    Guardar *g = new Guardar();
    setTableroActual();
    //le envio el avance del tablero y el juego resuelto para su posterior solucion
    g->guardarValores(tableroActual, matriz);
    g->crearArchivo();
}


void MainTable::cargarPartida()
{
    Guardar *g = new Guardar();
    //le envio para que me setee los valores de como acabo el juego y la solucion del mismo
    g->leerArchivo(tableroActual, matriz);
    setTableroEnPantalla();
}
