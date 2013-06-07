#include "maintable.h"
#include "ui_maintable.h"
#include <QLineEdit>
#include <QGridLayout>
#include <QApplication>
#include <QString>
#include <QLayoutItem>
#include <QDebug>

MainTable::MainTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainTable)
{
    ui->setupUi(this);
    initGui();
}

MainTable::~MainTable()
{
    delete ui;
}

void MainTable::initGui()
{
    int k = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            numberField[k] = new QLineEdit(QString::number(k),0);
            ui->tablero->addWidget(numberField[k],i,j);
            k++;
        }
    }

    connect(ui->cmdVerificar, &QPushButton::clicked, this, &MainTable::verify_clicked);
}

void MainTable::verify_clicked(){
    //int k = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            QLayoutItem *qli = ui->tablero->itemAtPosition(i,j);
            QLineEdit *qle = (QLineEdit*)(qli->widget());
            QString srt = qle->text();
            qDebug() << srt;
            matriz[i][j] = srt.toInt();
        }
    }
}
