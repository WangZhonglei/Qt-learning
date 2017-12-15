#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //pixmap是放图片的类，右键图片名，拷贝路径
    QPixmap pixmap(":/new/images/Planet_Odd_Logo.png");
    //定义画板
    QPalette palette;
    //设置画刷
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    //应用画板
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}
