/*!
* @file about.h
* @brief Este archivo contiene la info de los creadores del juego
* @short Este archivo contiene la info de los creadores del juego
*
* @author Jefferson Rivera
* @author Rúben Carbajal
* @author César Madrid
*
* @date 07/07/2013
**/
#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
class about;
}
/**
 * @brief The about es la clase que se encarga de mostrar la informacion en about del programa
 */
class about : public QDialog
{
    Q_OBJECT
    
public:
    /**
         * @brief El contructor de la clase
         * @param
         */
    explicit about(QWidget *parent = 0);
    ~about();
    
private slots:
    /**
     * @brief on_pushButton_clicked slot para el menu Acerca De
     */
    void on_pushButton_clicked();

private:
    Ui::about *ui;
};

#endif // ABOUT_H
