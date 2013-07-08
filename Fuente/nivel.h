/**
* @file nivel.h
* @brief Clase encargado de emitir señales segun el nivel de dificultad de tablero
* @author Jefferson Rivera
* @author Rúben Carbajal
* @author César Madrid
*
* @date 07/07/2013
*/
#ifndef NIVEL_H
#define NIVEL_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class nivel;
}

class nivel : public QDialog
{
    Q_OBJECT
    
public:
    explicit nivel(QWidget *parent = 0);
    ~nivel();

signals:
    void appReady(int i);

private:
    Ui::nivel *ui;

    //Procedimientos
    void initGui();
    void emitirNivel();
    void setImagen();

    //Atributos
    QPushButton *levels[4];


};

#endif // NIVEL_H
