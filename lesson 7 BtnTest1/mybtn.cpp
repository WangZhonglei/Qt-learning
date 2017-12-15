#include<QDebug>  //Btn1
#include<QMessageBox>  //Btn2
#include<QMenu>  //Btn4
#include "mybtn.h"
#include "ui_mybtn.h"

MyBtn::MyBtn(QWidget *parent) : QDialog(parent), ui(new Ui::MyBtn)
{
    ui->setupUi(this);
    connect(ui->pushButton2,SIGNAL(clicked(bool)),this,SLOT(onBtn2()));
    ui->pushButton3->installEventFilter(this);  //给Btn3添加事件

    //创建菜单，添加按钮，并把菜单加到Btn4上
    QMenu *menu = new QMenu;
    menu->addAction("打开");
    menu->addAction("关闭");
    ui->pushButton4->setMenu(menu);

}

MyBtn::~MyBtn()
{
    delete ui;
}

void MyBtn::on_pushButton1_clicked()
{
    qDebug()<<"You clicked Btn1";

}

void MyBtn::onBtn2()
{
    QMessageBox::information(this,"Btn2","You clicked Btn2");
}


bool MyBtn::eventFilter(QObject *o, QEvent *e)
{
    if(e->type() == QEvent::HoverEnter) //鼠标进入
    {
        if(o == ui->pushButton3)        //是否是当前按钮
        {
            ui->pushButton3->setStyleSheet("background-color: rgb(255, 0, 0);");
            qDebug()<<"Btn3 Enter";
        }
        else
        {
            return QObject::eventFilter(o,e);
        }
    }
    else if(e->type() == QEvent::HoverLeave)
    {
        if(o == ui->pushButton3)
        {
            ui->pushButton3->setStyleSheet("background-color: rgb(255, 255, 0);");
            qDebug()<<"Btn3 Leave";

        }
        else
        {
            return QObject::eventFilter(o,e);
        }
    }
    else
    {
        return QObject::eventFilter(o,e);
    }

}
