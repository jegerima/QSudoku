#ifndef MAINTABLE_H
#define MAINTABLE_H

#include <QMainWindow>

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
    void verify_clicked();

private:
    void initGui();
    
    Ui::MainTable *ui;
    QLineEdit *numberField[81];
    int matriz[9][9];
};

#endif // MAINTABLE_H
