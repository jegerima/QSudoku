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

    //Atributos
    QPushButton *levels[4];


};

#endif // NIVEL_H
