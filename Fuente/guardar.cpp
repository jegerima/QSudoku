#include "guardar.h"
#include "simplecrypt.h"
#include <QDebug>
#include <QRegExp>
#include <QStringList>
#include <QFileDialog>
#include <QTranslator>


Guardar::Guardar()
{
}

void Guardar::crearArchivo()
{
    QFileDialog dialog(NULL);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setDefaultSuffix("su");
    QFile file(dialog.getSaveFileName(NULL, "Guardar", QDir::homePath()+".su","Any Files (*.su)" ));

    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
    QTextStream out(&file);
    //out << (qint16)1;


    //qDebug()<<dialog.getSaveFileName(NULL, QDir::homePath(),"(nombre)*.su");

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
void Guardar::guardarValores(int m[9][9], int sol[9][9], QString jugador, QString tiempo)
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
    cadenaAGuardar.append("-");
    //concateno el nombre del jugador
    cadenaAGuardar = cadenaAGuardar + jugador;
    cadenaAGuardar.append("-");
    cadenaAGuardar = cadenaAGuardar + tiempo;
    qDebug() << cadenaAGuardar;
}


//m es el tablero actual y sol es la solucion
void Guardar::leerArchivo(int matrix[9][9], int sol[9][9], QString *name, QTime *t)
{
    int k=0;
    QString nombreArchivo = QFileDialog::getOpenFileName(NULL, "Carga archivo", QDir::homePath(), "*.su");

    QFile file(nombreArchivo);
    if(file.open(QIODevice::ReadOnly))
    {
    QTextStream in(&file);
    QString c(in.readAll());
    SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //el mismo aleatorio
    QString decrypted = crypto.decryptToString(c);
    qDebug() << c << decrypted;
    //sacar el tablero guardado y los ultimos que jugo
    QRegExp rx("-");
    QStringList actualYsolucion = decrypted.split(rx);
    qDebug() << actualYsolucion;
    QString actual = actualYsolucion[0];
    QString solucion = actualYsolucion[1];
    QString nombre = actualYsolucion[2];
    *name = nombre;
    QRegExp rxh(":");
    QString tiempo = actualYsolucion[3];
    QStringList HMS = tiempo.split(rxh);
    QString h = HMS[0];
    QString m = HMS[1];
    QString s = HMS[2];
    t->setHMS(h.toInt(), m.toInt(), s.toInt());
    QChar tmp, tmp1;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            tmp = actual[k];
            tmp1 = solucion[k];
            matrix[i][j] = tmp.digitValue();
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




