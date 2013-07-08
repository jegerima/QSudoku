/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QLabel *lbl_espol;
    QLabel *lbl_logo;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QStringLiteral("about"));
        about->resize(320, 240);
        lbl_espol = new QLabel(about);
        lbl_espol->setObjectName(QStringLiteral("lbl_espol"));
        lbl_espol->setGeometry(QRect(220, 100, 80, 80));
        lbl_espol->setPixmap(QPixmap(QString::fromUtf8(":/Recursos/espol.gif")));
        lbl_espol->setScaledContents(true);
        lbl_logo = new QLabel(about);
        lbl_logo->setObjectName(QStringLiteral("lbl_logo"));
        lbl_logo->setGeometry(QRect(10, -10, 291, 111));
        lbl_logo->setPixmap(QPixmap(QString::fromUtf8(":/Recursos/icon640.png")));
        lbl_logo->setScaledContents(true);
        label = new QLabel(about);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 110, 161, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(about);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 150, 121, 17));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(about);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 170, 121, 16));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(about);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 190, 121, 16));
        label_4->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(about);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 200, 99, 27));

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QApplication::translate("about", "Acerca de", 0));
        lbl_espol->setText(QString());
        lbl_logo->setText(QString());
        label->setText(QApplication::translate("about", "QSudoku Version 1.0.1", 0));
        label_2->setText(QApplication::translate("about", "Jefferson Rivera", 0));
        label_3->setText(QApplication::translate("about", "Ruben Carvajal", 0));
        label_4->setText(QApplication::translate("about", "Cesar Madrid", 0));
        pushButton->setText(QApplication::translate("about", "Aceptar", 0));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
