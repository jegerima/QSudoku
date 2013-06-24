/********************************************************************************
** Form generated from reading UI file 'maintable.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTABLE_H
#define UI_MAINTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainTable
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *tablero;
    QPushButton *cmdVerificar;
    QPushButton *cmdGen;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainTable)
    {
        if (MainTable->objectName().isEmpty())
            MainTable->setObjectName(QStringLiteral("MainTable"));
        MainTable->resize(673, 509);
        centralWidget = new QWidget(MainTable);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 531, 431));
        tablero = new QGridLayout(gridLayoutWidget);
        tablero->setSpacing(1);
        tablero->setContentsMargins(11, 11, 11, 11);
        tablero->setObjectName(QStringLiteral("tablero"));
        tablero->setContentsMargins(0, 0, 0, 0);
        cmdVerificar = new QPushButton(centralWidget);
        cmdVerificar->setObjectName(QStringLiteral("cmdVerificar"));
        cmdVerificar->setGeometry(QRect(570, 40, 81, 27));
        cmdGen = new QPushButton(centralWidget);
        cmdGen->setObjectName(QStringLiteral("cmdGen"));
        cmdGen->setGeometry(QRect(570, 10, 81, 27));
        MainTable->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainTable);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 673, 25));
        MainTable->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainTable);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainTable->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainTable);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainTable->setStatusBar(statusBar);

        retranslateUi(MainTable);

        QMetaObject::connectSlotsByName(MainTable);
    } // setupUi

    void retranslateUi(QMainWindow *MainTable)
    {
        MainTable->setWindowTitle(QApplication::translate("MainTable", "QSudoku 0.1.20", 0));
        cmdVerificar->setText(QApplication::translate("MainTable", "Verificar", 0));
        cmdGen->setText(QApplication::translate("MainTable", "Generar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainTable: public Ui_MainTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTABLE_H
