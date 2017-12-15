#include "mytimer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTimer w;
    w.show();

    QTimer::singleShot(5000, &a, SLOT(quit()));  //单次执行，启动5s退出

    return a.exec();
}
