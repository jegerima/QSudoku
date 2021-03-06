#include "maintable.h"
#include "ui_maintable.h"
#include "genmatriz.h"
#include "about.h"
#include "guardar.h"
#include <QLineEdit>
#include <QGridLayout>
#include <QApplication>
#include <QString>
#include <QLayoutItem>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <stdio.h>
#include <QFrame>
#include <iostream>
#include <time.h>

MainTable::MainTable(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainTable)
{
    ui->setupUi(this);
    hints = 0;
    QMessageBox::information(0,tr("QSudoku Message"),tr("Bienvenido a QSudoku. Version 0.2.05"));

    //Interfaces
    initGuiCelda();
    initMenuBar();
    initTeclado();
    setIcono();
    this->setFixedSize(this->size());

    //Formulario de niveles
    level = new nivel(0);
    connect(level, SIGNAL(appReady(int)), this, SLOT(iniciarJuego(int)));

    srand (time(NULL));
    ui->crono->display("00:00");
}

MainTable::~MainTable()
{
    delete ui;
}

void MainTable::initGuiCelda()
{
    //Matriz del Sudoku
    int i,j;
    ui->cmdVerificar->setEnabled(false);
    ui->cmdHint->setEnabled(false);
    ui->tablero->setHorizontalSpacing(8);
    ui->tablero->setVerticalSpacing(8);
    int fil = 0, col=0;
    for(i = 0; i < 3; i++)
    {
        fil = i*3;
        for(j = 0; j < 3; j++)
        {
            col = j*3;
            QGridLayout *cuadro = new QGridLayout();
            cuadro->setHorizontalSpacing(1);
            cuadro->setVerticalSpacing(1);
            for(int l = 0; l < 3; l++)
            {
                for(int m = 0; m < 3; m++)
                {
                    Celda *cas = new Celda(0, QPoint(fil, col)); //Parametro del constructor ==> ((j*3)+m+(i*27)+(l*9))
                    cas->setValue(0);
                    connect(cas,SIGNAL(clicked()),this,SLOT(getCeldaRunTime()));
                    connect(cas,SIGNAL(clicked()),cas, SLOT(setEmpty()));
                    cuadro->addWidget(cas,l,m);
                    //qDebug()<< fil<< col;
                    col++;
                }
            fil++;
            col = j*3;
            }

            ui->tablero->addLayout(cuadro,i,j);
            fil = i*3;
        }


    }
    //Celda temporal para el tiempo de ejecucion
    celdaRuntime = new Celda(0, QPoint(0,0));
    tm = new QTime(0,0,0,0);
    avanceMin = 0;
    avanceSeg = 0;
}

void MainTable::initMenuBar()
{
    connect(ui->actionNueva, SIGNAL(triggered()), this, SLOT(nuevaPartida())); //Menu Partida->Nueva
    connect(ui->actionCargar, SIGNAL(triggered()), this, SLOT(cargarPartida())); //Menu Partida->Cargar
    connect(ui->actionGuardar, SIGNAL(triggered()), this, SLOT(guardarPartida())); //Menu Partida->Guardar
    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(salirJuego())); //Menu Partida->Salir
    connect(ui->actionAcerca_de, SIGNAL(triggered()), this, SLOT(acercaDe())); //Menu AcercaDe
}

void MainTable::initCrono()
{
    tiempo = new QTimer(this);
    connect(tiempo, SIGNAL(timeout()), this, SLOT(timeRefresh()));
    tiempo->start(1000);
    tiempoIni = QTime::currentTime();
    QTimer::singleShot(1000, this, SLOT(timeRefresh()));
}

void MainTable::initTeclado()
{
    int z = 0;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3 ; j++)
        {
            QPushButton *cmd = new QPushButton(QString("%1").arg(z+1));
            cmd->setEnabled(false);
            this->teclado[z] = cmd;
            connect(teclado[z], SIGNAL(clicked()), this, SLOT(numPressed()));
            ui->tecladoNum->addWidget(teclado[z],i,j);
            z++;
        }
    }
    QPushButton *cmd = new QPushButton(QString("0"));
    cmd->setEnabled(false);
    this->teclado[z] = cmd;
    connect(teclado[z], SIGNAL(clicked()), this, SLOT(numPressed()));
    ui->tecladoNum->addWidget(teclado[z],4,1);
}

void MainTable::timeRefresh()
{
    int m, m_ini, m_act, s, s_ini, s_act, ms, ms_ini, ms_act = 0;
    QTime actual = QTime::currentTime();
    m_ini = tiempoIni.minute();
    s_ini = tiempoIni.second();
    ms_ini = tiempoIni.msec();
    m_act = actual.minute();
    s_act = actual.second();
    ms_act = actual.msec();

    if (ms_act < ms_ini)
    {
        ms_act = 1000 + ms_act;
        s_act = s_act -1;
    }

    if (s_act < s_ini)
    {
    	s_act = 60 + s_act;
	m_act = m_act -1;
    }

    m = m_act - m_ini +avanceMin;
    s = s_act - s_ini +avanceSeg;
    ms = ms_act - ms_ini;
    //actualizo el tiempo

    qDebug("%d:%d:%d",m,s,ms);
    qDebug("%d,%d",avanceMin,avanceSeg);

    tm->setHMS(0, m, s, ms);
    ui->crono->display(tm->toString("mm:ss"));
}

void MainTable::setTableroInicio()
{
    //genera una nueva solucion de tablero para comenzar todo
    GenMatriz *matrizSolucion = new GenMatriz();
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
    ui->cmdHint->setEnabled(true);
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
            tmp = ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->getValue();
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
                 if(tableroInicial[i][j]!=0)
                     ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))
                                ->itemAtPosition(i%3,j%3))->widget()))->setDisabled(true);
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
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            tableroInicial[i][j]=0;

    if(n==0){
        qDebug("Seteando nivel 1");
        for(int i=0; i<51; i++){
            fila = rand()%9;
            col = rand()%9;
            tableroActual[fila][col] = matriz[fila][col];
            tableroInicial[fila][col] = matriz[fila][col];
        }
    }
    if(n==1){
        qDebug("Seteando nivel 2");
        for(int i=0; i<43; i++){
            fila = rand()%9;
            col = rand()%9;
            tableroActual[fila][col] = matriz[fila][col];
            tableroInicial[fila][col] = matriz[fila][col];
        }
    }
    if(n==2){
        qDebug("Seteando nivel 3");
        for(int i=0; i<35; i++){
            fila = rand()%9;
            col = rand()%9;
             tableroActual[fila][col] = matriz[fila][col];
             tableroInicial[fila][col] = matriz[fila][col];
        }
    }
    if(n==3){
        qDebug("Seteando nivel Dios");
        for(int i=0; i<27; i++){
            fila = rand()%9;
            col = rand()%9;
             tableroActual[fila][col] = matriz[fila][col];
             tableroInicial[fila][col] = matriz[fila][col];
        }
    }
}

void MainTable::acercaDe()
{
    about *ab = new about();
    ab->setWindowModality(Qt::ApplicationModal);
    ab->show();

}

void MainTable::setIcono()
{
    //ui->iconFrame->setStyleSheet("background-image: url(/home/jegerima/ReposGit/QSudoku/Recursos/i160x130.png)");
}

void MainTable::setCeldasBlanco()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->setBackColor("white");
        }
    }

}


void MainTable::nuevaPartida()
{
    level->show();
}

void MainTable::iniciarJuego(int n)
{
    avanceMin = 0;
    avanceSeg = 0;
    level->hide();
    activarTeclado();
    setCeldasBlanco();
    setTableroInicio();
    setTableroInicialSegunNivel(n);
    setTableroEnPantalla();
    qDebug("%d",n);
    do
    {
        jugador = QInputDialog::getText(this, tr("QSudoku Request"),tr("Ingrese su nombre:"));
        if(jugador==NULL)
        {
            QMessageBox::warning(this,tr("Qsudoku Message"),tr("No se ha ingresado texto"));
        }
    }while(jugador== NULL);
    ui->lbl_jugador->setText(jugador);
    switch(n)
    {
        case 0:
        {
            ui->lbl_level->setText("Novato");
            hints = 12;
            dificultad = 0;
            break;
        }
        case 1:
        {
            ui->lbl_level->setText("Intermedio");
            hints = 8;
            dificultad = 1;
            break;
        }
        case 2:
        {
            ui->lbl_level->setText("Profesional");
            hints = 4;
            dificultad = 2;
            break;
        }
        default:
        {
            ui->lbl_level->setText("Leyenda");
            hints = 2;
            dificultad = 3;
            break;
        }
    }
    initCrono();
    ui->cmdHint->setText(QString("Hints("+QString::number(hints)+")"));
}

void MainTable::salirJuego()
{
    QMessageBox msgBox;
    int punt = calcularPuntaje();
    QString p = QString::number(punt);
    msgBox.setText("Su puntaje fue de: "+p);
    msgBox.exec();
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
                ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->setBackColor("red"); //pintar casillas erradas de rojo
                ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->setBlackBorder();
                t = false;
            }
            if( !(checkColumna(i,j) ) )
            {
                ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->setBackColor("red");//pintar casillas erradas de rojo
                ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->setBlackBorder();
                t = false;
            }
            if( !(checkCuadro(i,j) ) )
            {
                ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->setBackColor("red");//pintar casillas erradas de rojo
                ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(i/3,j/3))->itemAtPosition(i%3,j%3))->widget()))->setBlackBorder();
                t = false;
            }

        }
    }
    if(t == true) //mensaje de confirmacion de que esta correceto
        QMessageBox::warning(0,tr("QSudoku Message"),"Sudoku resuelto correctamente.");
    else
        QMessageBox::warning(0,tr("QSudoku Message"),"El sudoku se encuentra incorrecto.");

}

void MainTable::getCeldaRunTime()
{
    //Permite obtener la celda que ha sido clickeada
    if(celdaRuntime)
    {
        celdaRuntime->reset();
        celdaRuntime->setBlackBorder();
    }
    celdaRuntime = (Celda*)(sender());
    setTableroActual();
    setPistas();

}

void MainTable::setPistas()
{
    pistas.clear();
    pistas <<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9";
    int fila = celdaRuntime->pos.x();
    int col = celdaRuntime->pos.y();
    int tmp=0;
    for(int i=0; i<9; i++){
        tmp = tableroActual[fila][i];
        if(tmp!=0){
            pistas[tmp-1] = QString("0");
        }
    }
    for(int j=0; j<9; j++){
        tmp = tableroActual[j][col];
        if(tmp!=0){
            pistas[tmp-1] = QString("0");
        }
    }
    //validacion pistas cuadro
    int l =(((col/3)+1)+(fila/3)*3);
    for(int i=(((l-1)/3)*3);i<((((l-1)/3)*3)+3);i++){
        for(int j=(((l-1)%3)*3);j<((((l-1)%3)*3)+3);j++){
            tmp = tableroActual[i][j];
            if(tmp!=0)
                pistas[tmp-1] = QString("0");
        }
    }

    //le estamos dando maximo 5 pistas para que pueda colocar
    int k=0;
    for(int j=0; j<9; j++){

        tmp = pistas[j].toInt();
        if(tmp!=0 && k<5){
            celdaRuntime->addHint(tmp);
            k++;
        }
    }

}


void MainTable::numPressed()
{
    QString srt = ((QPushButton*)sender())->text();
    qDebug()<<srt;
    celdaRuntime->setValue(srt.toInt());
}

void MainTable::guardarPartida()
{
    Guardar *g = new Guardar();
    setTableroActual();
    //le envio el avance del tablero y el juego resuelto para su posterior solucion
    //el nombre del jugador y el tiempo que llevaba jugando


    g->guardarValores(tableroActual, matriz, jugador, ui->lbl_level->text(), tm->toString(),tableroInicial,hints);
    g->crearArchivo();
}


void MainTable::cargarPartida()
{
    Guardar *g = new Guardar();
    QString nivel;
    //le envio para que me setee los valores de como acabo el juego y la solucion del mismo
    g->leerArchivo(tableroActual, matriz, &jugador, &nivel, tm,tableroInicial,&hints);
    if(jugador==NULL)
        return;
    avanceMin = tm->minute();
    avanceSeg = tm->second();
    //ui->crono->display(tm->toString("mm:ss"));
    ui->lbl_jugador->setText(jugador);
    ui->lbl_level->setText(nivel);
    ui->cmdHint->setEnabled(true);
    ui->cmdHint->setText(QString("Hints("+QString::number(hints)+")"));
    setCeldasBlanco();
    setTableroEnPantalla();
    activarTeclado();
    initCrono();
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

void MainTable::on_cmdHint_clicked()
{
    int irnd, jrnd = 0;

    if(hints>0)
    {
        hints = hints - 1;
        ((QPushButton*)sender())->setText(QString("Hints("+QString::number(hints)+")"));
        setTableroActual();
        do
        {
            irnd = rand()%8 + 1;
            jrnd = rand()%8 + 1;
        }
        while(tableroActual[irnd][jrnd]!=0);
        tableroActual[irnd][jrnd] = matriz[irnd][jrnd];
        ((Celda*)(((QLayoutItem*)((QGridLayout*)ui->tablero->itemAtPosition(irnd/3,jrnd/3))
                   ->itemAtPosition(irnd%3,jrnd%3))->widget()))->setValue(tableroActual[irnd][jrnd]);
    }
    else
    {
        QMessageBox::warning(this,tr("QSudoku Message"),tr("No le quedan ayudas disponibles"));
    }
}

int MainTable::calcularPuntaje()
{
    int a, b=0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            a = tableroActual[i][j];
            if(a!=0)
                b++;
        }
    }

    if(dificultad==0)
        return (b-30)*10;
    if(dificultad==1)
        return (b-25)*15;
    if(dificultad==2)
        return (b-20)*20;
    if(dificultad==3)
        return (b-15)*25;
    return 0;

}

void MainTable::activarTeclado()
{
    for(int i = 0; i<10; i++)
        teclado[i]->setEnabled(true);
}
