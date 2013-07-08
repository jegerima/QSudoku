/********************************************************************************
** Form generated from reading UI file 'nivel.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVEL_H
#define UI_NIVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nivel
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *lyLevel;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *nivel)
    {
        if (nivel->objectName().isEmpty())
            nivel->setObjectName(QStringLiteral("nivel"));
        nivel->setWindowModality(Qt::WindowModal);
        nivel->resize(360, 358);
        nivel->setWindowTitle(QStringLiteral("QSudoku - Niveles"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Recursos/i160x130.png"), QSize(), QIcon::Normal, QIcon::Off);
        nivel->setWindowIcon(icon);
        nivel->setAutoFillBackground(false);
        verticalLayoutWidget = new QWidget(nivel);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(100, 150, 160, 191));
        lyLevel = new QVBoxLayout(verticalLayoutWidget);
        lyLevel->setObjectName(QStringLiteral("lyLevel"));
        lyLevel->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(nivel);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 120, 231, 17));
        label_2 = new QLabel(nivel);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, -10, 321, 121));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Recursos/icon640.png")));
        label_2->setScaledContents(true);

        retranslateUi(nivel);

        QMetaObject::connectSlotsByName(nivel);
    } // setupUi

    void retranslateUi(QDialog *nivel)
    {
        label->setText(QApplication::translate("nivel", "Seleccione un nivel de dificultad:", 0));
        label_2->setText(QString());
        Q_UNUSED(nivel);
    } // retranslateUi

};

namespace Ui {
    class nivel: public Ui_nivel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVEL_H
