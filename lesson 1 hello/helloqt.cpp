#include<QApplication>
#include<QLabel>  //显示文本使用的控件

int main(int argc , char *argv[])
{
    QApplication app(argc, argv);

    QLabel *label = new QLabel("<h1><font color = red>Hello </font> <br/>Qt </h1>");
    label->show();

    return app.exec();  //让程序进入循环
}
