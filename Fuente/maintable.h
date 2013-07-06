#ifndef MAINTABLE_H
#define MAINTABLE_H

#include <QMainWindow>
#include <celda.h>

namespace Ui {
class MainTable;
}

class QLineEdit;
class QGridLayout;

class MainTable : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainTable(QWidget *parent = 0);
    ~MainTable();
    
private slots:
    void on_cmdVerificar_clicked();

    void on_guardar_clicked();

    void on_cargar_clicked();

private:

    //Atributos
    int matriz[9][9];
    int tableroActual[9][9];

    //Procedimientos
    void initGuiCelda();
    void setTableroPrevio();
    void setTableroAGuardar();
    void setTableroAJugar();

    //Funciones
    Ui::MainTable *ui;
    bool checkFila(int row, int column);
    bool checkColumna(int row, int column);
    bool checkCuadro(int row, int column);

};

#endif // MAINTABLE_H
