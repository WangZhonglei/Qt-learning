#include "radiobutton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RadioButton w;
    w.show();

    return a.exec();
}
