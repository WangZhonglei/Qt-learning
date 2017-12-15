#include "mylistwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyListWidget w;
    w.show();

    return a.exec();
}
