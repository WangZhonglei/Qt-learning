#include "logdlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Logdlg w;
    w.show();

    return a.exec();
}
