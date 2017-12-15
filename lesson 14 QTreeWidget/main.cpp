#include "treewidget.h"
#include <QApplication>

//在此设置样式表

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TreeWidget w;
    w.show();

    return a.exec();
}
