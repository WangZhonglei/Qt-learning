#include <QApplication>
#include <QSlider>  //滑动条控件
#include <QSpinBox> //微调框
#include <QHBoxLayout>  //布局

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *widget = new QWidget; //实例化主界面
    widget->setWindowTitle("Layout");

    QSlider *slider = new QSlider(Qt::Horizontal);
    QSpinBox *spinbox = new QSpinBox; //定义微调框
    slider->setRange(0,100); //设置滑动范围
    spinbox->setRange(0,100);

    //将new出的两个对象的信号与槽互相绑定
    QObject::connect(slider,SIGNAL(valueChanged(int)),spinbox,SLOT(setValue(int)));
    QObject::connect(spinbox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));

    QHBoxLayout *hlayout = new QHBoxLayout;  //定义水平摆放的变量
    hlayout->addWidget(spinbox);  //将控件加入布局
    hlayout->addWidget(slider);

    widget->setLayout(hlayout); //将布局放入进去
    widget->show();

    return a.exec();
}
