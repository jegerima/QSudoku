#include "genmatriz.h"
#include <QDebug>


GenMatriz::GenMatriz()
{
    llenarMatrizSemilla();
    generarArreglos();
    imprimirMatriz(matrizSeed);
    generarMatrizSudoku();
    imprimirMatriz(matriz);
}

void GenMatriz::llenarMatrizSemilla()
{
    int k=0;
    int valores[81] = {2,7,1,6,3,4,8,5,9,
                       5,6,9,8,2,7,3,1,4,
                       4,3,8,1,5,9,6,2,7,
                       6,8,2,5,4,1,7,9,3,
                       1,9,4,2,7,3,5,8,6,
                       7,5,3,9,6,8,2,4,1,
                       8,1,7,3,9,2,4,6,5,
                       9,4,6,7,8,5,1,3,2,
                       3,2,5,4,1,6,9,7,8};
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                matrizSeed[i][j] = valores[k];
                k++;
            }
        }
}

void GenMatriz::generarMatrizSudoku()
{
    int aleatorio, tmp;
    QList<int> numeros;
    numeros <<1<<2<<3<<4<<5<<6<<7<<8<<9;
    QList<int> aleatorios;
    for(int i=9; i>0; i--){
        aleatorio = rand()%(i);
        qDebug() << "rand:"<<aleatorio;
        tmp = numeros.takeAt(aleatorio);
        aleatorios.append(tmp);
    }
    colocarNumeros(aleatorios);
}


int GenMatriz::arregloDeNumeros(int i, int j)
{
    return matriz[i][j];
}

void GenMatriz::guardarPosNum(int n, int fila, int columna)
{
    if(n==1) num1.append(QPoint(fila, columna));
    if(n==2) num2.append(QPoint(fila, columna));
    if(n==3) num3.append(QPoint(fila, columna));
    if(n==4) num4.append(QPoint(fila, columna));
    if(n==5) num5.append(QPoint(fila, columna));
    if(n==6) num6.append(QPoint(fila, columna));
    if(n==7) num7.append(QPoint(fila, columna));
    if(n==8) num8.append(QPoint(fila, columna));
    if(n==9) num9.append(QPoint(fila, columna));
}


void GenMatriz::generarArreglos()
{
    int tmp=0;//temporal
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            tmp = matrizSeed[i][j];
            guardarPosNum(tmp, i, j);
        }
    }
}

void GenMatriz::imprimirMatriz(int matriz[9][9])
{
    for(int i=0; i<9; i++){
    for(int j = 0; j < 9; j++)
    {
        qDebug() << matriz[i][j];
    }
    }
}

void GenMatriz::colocarNumeros(QList<int> aleatorios){
    int tmp, fila, columna, tmp2;
    tmp2=1;
    for(int i = 0; i < 9; i++)
    {
        tmp=aleatorios.value(i);//siempre tomo el primero
        qDebug() << tmp;
        if(tmp2==1){
            for(int j=0; j<9; j++){
                fila = num1.value(j).x();
                qDebug()<<"1 fila"<<fila;
                columna = num1.value(j).y();
                qDebug()<<"1 columna"<<columna;
                matriz[fila][columna]=tmp;
            }
        }
        if(tmp2==2){
            for(int j=0; j<9; j++){
                fila = num2.value(j).x();//num2.value(j).x();
                qDebug()<<"2 fila"<<fila;
                columna = num2.value(j).y();
                qDebug()<<"2 columna"<<columna;
                matriz[fila][columna]=tmp;
            }
        }
        if(tmp2==3){
            for(int j=0; j<9; j++){
                fila = num3.value(j).x();
                qDebug()<<"3 fila"<<fila;
                columna = num3.value(j).y();
                qDebug()<<"3 columna"<<columna;
                matriz[fila][columna]=tmp;
            }
        }
        if(tmp2==4){
            for(int j=0; j<9; j++){
                fila = num4.value(j).x();
                qDebug()<<"4 fila"<<fila;
                columna = num4.value(j).y();
                qDebug()<<"4 columna"<<columna;
                matriz[fila][columna]=tmp;
            }
        }
        if(tmp2==5){
            for(int j=0; j<9; j++){
                fila = num5.value(j).x();
                qDebug()<<"5 fila"<<fila;
                columna = num5.value(j).y();
                qDebug()<<"5 columna"<<columna;
                matriz[fila][columna]=tmp;
            }
        }
        if(tmp2==6){
            for(int j=0; j<9; j++){
                fila = num6.value(j).x();
                qDebug()<<"6 fila"<<fila;
                columna = num6.value(j).y();
                qDebug()<<"6 columna"<<columna;
                matriz[fila][columna]=tmp;
            }
        }
        if(tmp2==7){
            for(int j=0; j<9; j++){
                fila = num7.value(j).x();
                qDebug()<<"7 fila"<<fila;
                columna = num7.value(j).y();
                qDebug()<<"7 columna"<<columna;
                matriz[fila][columna]=tmp;
            }
        }
        if(tmp2==8){
            for(int j=0; j<9; j++){
                fila = num8.value(j).x();
                qDebug()<<"8 fila"<<fila;
                columna = num8.value(j).y();
                qDebug()<<"8 columna"<<columna;
                matriz[fila][columna]=tmp;
            }
        }
        if(tmp2==9){
            for(int j=0; j<9; j++){
                fila = num9.value(j).x();
                qDebug()<<"9 fila"<<fila;
                columna = num9.value(j).y();
                qDebug()<<"9 columna"<<columna;
                matriz[fila][columna]=tmp;
            }
        }
    tmp2++;
    }

}
