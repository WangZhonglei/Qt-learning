#include <QApplication>    //#include <QCoreApplication>
#include <QPushButton>   //按钮头文件

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     //定义按钮，参数是显示的文字,英文可以注释掉tr
    QPushButton *Btn = new QPushButton(/*QObject::tr*/("Quit"));
    QObject::connect(Btn,SIGNAL(clicked(bool)),&a,SLOT(quit()));  //绑定
    Btn->show();

    return a.exec();
}
