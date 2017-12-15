#include "dialog.h"
#include <QApplication>
#include<QUiLoader>
#include<QFile>
#include<QWidget>

#include<QDir>
#include<QDebug>

#include<QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //测试时以下两行删除
    Dialog w;
    w.show();
/*    //打印出当前的路径
    qDebug()<<QDir::currentPath();

    QUiLoader uiLoader;
    QFile file("../DesignerTest/dialog.ui"); //右键界面文件，expl打开，找到ui文件
    //定义一个控件，指向它
    QWidget *widget = uiLoader.load(&file);
    if(widget)
    {
        //findChild获取ui文件界面上控件的指针，从而可以做出相应改变
        QPushButton *btn =widget->findChild<QPushButton*>("pushButton");
        btn->setText("Test");
        widget->show();
    }
*/
    return a.exec();
}
