#include "mybtn.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyBtn w;
    w.show();

    return a.exec();
}
