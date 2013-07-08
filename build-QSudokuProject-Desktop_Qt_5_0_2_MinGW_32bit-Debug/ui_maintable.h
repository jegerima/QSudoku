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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainTable
{
public:
    QAction *actionCargar;
    QAction *actionGuardar;
    QAction *actionSalir;
    QAction *actionNueva;
    QAction *actionPreferencias;
    QAction *actionAcerca_de;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *tablero;
    QPushButton *cmdVerificar;
    QLabel *label;
    QLabel *lbl_jugador;
    QLCDNumber *crono;
    QLabel *label_2;
    QLabel *lbl_level;
    QLabel *lbl_icon;
    QWidget *gridLayoutWidget_2;
    QGridLayout *tecladoNum;
    QPushButton *cmdHint;
    QMenuBar *Menu;
    QMenu *menuPartida;
    QMenu *menuAcerca_de;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainTable)
    {
        if (MainTable->objectName().isEmpty())
            MainTable->setObjectName(QStringLiteral("MainTable"));
        MainTable->resize(720, 519);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Recursos/i160x130.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainTable->setWindowIcon(icon);
        actionCargar = new QAction(MainTable);
        actionCargar->setObjectName(QStringLiteral("actionCargar"));
        actionGuardar = new QAction(MainTable);
        actionGuardar->setObjectName(QStringLiteral("actionGuardar"));
        actionSalir = new QAction(MainTable);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionNueva = new QAction(MainTable);
        actionNueva->setObjectName(QStringLiteral("actionNueva"));
        actionPreferencias = new QAction(MainTable);
        actionPreferencias->setObjectName(QStringLiteral("actionPreferencias"));
        actionAcerca_de = new QAction(MainTable);
        actionAcerca_de->setObjectName(QStringLiteral("actionAcerca_de"));
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
        cmdVerificar->setGeometry(QRect(640, 350, 71, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(560, 130, 67, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        lbl_jugador = new QLabel(centralWidget);
        lbl_jugador->setObjectName(QStringLiteral("lbl_jugador"));
        lbl_jugador->setGeometry(QRect(560, 150, 151, 20));
        lbl_jugador->setAlignment(Qt::AlignCenter);
        crono = new QLCDNumber(centralWidget);
        crono->setObjectName(QStringLiteral("crono"));
        crono->setGeometry(QRect(560, 390, 151, 51));
        crono->setSegmentStyle(QLCDNumber::Filled);
        crono->setProperty("intValue", QVariant(0));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(560, 180, 67, 17));
        label_2->setFont(font);
        lbl_level = new QLabel(centralWidget);
        lbl_level->setObjectName(QStringLiteral("lbl_level"));
        lbl_level->setGeometry(QRect(560, 200, 151, 20));
        lbl_level->setAlignment(Qt::AlignCenter);
        lbl_icon = new QLabel(centralWidget);
        lbl_icon->setObjectName(QStringLiteral("lbl_icon"));
        lbl_icon->setGeometry(QRect(570, 10, 131, 111));
        lbl_icon->setFrameShape(QFrame::Box);
        lbl_icon->setFrameShadow(QFrame::Raised);
        lbl_icon->setPixmap(QPixmap(QString::fromUtf8(":/Recursos/i160x130.png")));
        lbl_icon->setScaledContents(true);
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(560, 230, 151, 111));
        tecladoNum = new QGridLayout(gridLayoutWidget_2);
        tecladoNum->setSpacing(6);
        tecladoNum->setContentsMargins(11, 11, 11, 11);
        tecladoNum->setObjectName(QStringLiteral("tecladoNum"));
        tecladoNum->setContentsMargins(0, 0, 0, 0);
        cmdHint = new QPushButton(centralWidget);
        cmdHint->setObjectName(QStringLiteral("cmdHint"));
        cmdHint->setGeometry(QRect(560, 350, 71, 27));
        MainTable->setCentralWidget(centralWidget);
        Menu = new QMenuBar(MainTable);
        Menu->setObjectName(QStringLiteral("Menu"));
        Menu->setGeometry(QRect(0, 0, 720, 25));
        menuPartida = new QMenu(Menu);
        menuPartida->setObjectName(QStringLiteral("menuPartida"));
        menuAcerca_de = new QMenu(Menu);
        menuAcerca_de->setObjectName(QStringLiteral("menuAcerca_de"));
        MainTable->setMenuBar(Menu);
        mainToolBar = new QToolBar(MainTable);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainTable->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainTable);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainTable->setStatusBar(statusBar);

        Menu->addAction(menuPartida->menuAction());
        Menu->addAction(menuAcerca_de->menuAction());
        menuPartida->addAction(actionNueva);
        menuPartida->addSeparator();
        menuPartida->addAction(actionCargar);
        menuPartida->addAction(actionGuardar);
        menuPartida->addSeparator();
        menuPartida->addAction(actionSalir);
        menuAcerca_de->addAction(actionPreferencias);
        menuAcerca_de->addSeparator();
        menuAcerca_de->addAction(actionAcerca_de);

        retranslateUi(MainTable);

        QMetaObject::connectSlotsByName(MainTable);
    } // setupUi

    void retranslateUi(QMainWindow *MainTable)
    {
        MainTable->setWindowTitle(QApplication::translate("MainTable", "QSudoku 0.2.05", 0));
        actionCargar->setText(QApplication::translate("MainTable", "Cargar", 0));
        actionCargar->setShortcut(QApplication::translate("MainTable", "Ctrl+C", 0));
        actionGuardar->setText(QApplication::translate("MainTable", "Guardar", 0));
        actionGuardar->setShortcut(QApplication::translate("MainTable", "Ctrl+G", 0));
        actionSalir->setText(QApplication::translate("MainTable", "Salir", 0));
        actionNueva->setText(QApplication::translate("MainTable", "Nueva", 0));
        actionPreferencias->setText(QApplication::translate("MainTable", "Preferencias", 0));
        actionAcerca_de->setText(QApplication::translate("MainTable", "Acerca de", 0));
        cmdVerificar->setText(QApplication::translate("MainTable", "Verificar", 0));
        label->setText(QApplication::translate("MainTable", "Jugador:", 0));
        lbl_jugador->setText(QString());
        label_2->setText(QApplication::translate("MainTable", "Nivel:", 0));
        lbl_level->setText(QString());
        lbl_icon->setText(QString());
        cmdHint->setText(QApplication::translate("MainTable", "Hints(0)", 0));
        menuPartida->setTitle(QApplication::translate("MainTable", "Partida", 0));
        menuAcerca_de->setTitle(QApplication::translate("MainTable", "Ajustes", 0));
    } // retranslateUi

};

namespace Ui {
    class MainTable: public Ui_MainTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTABLE_H
