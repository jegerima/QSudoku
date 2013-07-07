#include "guardar.h"
#include "simplecrypt.h"
#include <QDebug>
#include <QRegExp>
#include <QStringList>
#include <QFileDialog>


Guardar::Guardar()
{
}

void Guardar::crearArchivo()
{
    QFile file("/home/ruben/Documentos/out.su");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
    QTextStream out(&file);
    //out << (qint16)1;

     SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number
     QString result = crypto.encryptToString(cadenaAGuardar);
     out << result;
     QString decrypted = crypto.decryptToString(result);
     qDebug() << "cadena a guardar"+cadenaAGuardar << endl << "resul"+result << endl << "decriptado:"+decrypted;
     file.close();
    }
    else{
        qDebug("no se abrio el archivo");
    }
}

//guardo los valores como String, para su posterior encriptacion
void Guardar::guardarValores(int m[9][9], int sol[9][9])
{int tmp=0;
    //guardo el avance
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            tmp = m[i][j];
            cadenaAGuardar = cadenaAGuardar + QString::number(tmp);
        }
    }
    cadenaAGuardar.append("-");
    //concateno en el mismo String la solucion
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            tmp = sol[i][j];
            cadenaAGuardar = cadenaAGuardar + QString::number(tmp);
        }
    }
    qDebug() << cadenaAGuardar;
}


//m es el tablero actual y sol es la solucion
void Guardar::leerArchivo(int m[9][9], int sol[9][9])
{
    int k=0;
    QFile file("/home/ruben/Documentos/out.su");
    if(file.open(QIODevice::ReadOnly))
    {
    QTextStream in(&file);
    QString c(in.readAll());
    SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //el mismo aleatorio
    QString decrypted = crypto.decryptToString(c);
    qDebug() << c << decrypted;
    //sacar el tablero guardado y los ultimos que jugo
    QRegExp rx("\\D");
    QStringList actualYsolucion = decrypted.split(rx);
    qDebug() << actualYsolucion;
    QString actual = actualYsolucion[0];
    QString solucion = actualYsolucion[1];
    QChar tmp, tmp1;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            tmp = actual[k];
            tmp1 = solucion[k];
            m[i][j] = tmp.digitValue();
            sol[i][j] = tmp1.digitValue();
            k++;
        }
    }

    qDebug() <<"actual: "<< actualYsolucion[0] <<"solucion: "<< actualYsolucion[1];
    file.close();
    }
    else{
        qDebug("no se abrio el archivo");
    }

}

void Guardar::cargarValores(int m[9][9])
{

}


