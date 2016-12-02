#include <QApplication>
#include "dialog.h"
#include "tablero.h"

int main(int argc, char *argv[])
{
    QApplication aa(argc, argv);
    Dialog w;

    w.show();

    return aa.exec();
}
