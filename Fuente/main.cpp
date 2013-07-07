#include "maintable.h"
#include "nivel.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainTable w;
    w.show();
    
    return a.exec();
}
