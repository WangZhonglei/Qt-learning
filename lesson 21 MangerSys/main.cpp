#include "mainwindow.h"
#include <QApplication>
#include<QFile>
#include<QTextStream>
#include<QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置样式表
    QFile file(":/new/prefix1/styles/white.qss");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString style = in.readAll();
        file.close();
        qApp->setStyleSheet(style);
    }

    //设置字体
    QFont serifFont("Times", 10, QFont::Thin);
    a.setFont(serifFont);

    MainWindow w;
    w.show();

    return a.exec();
}
