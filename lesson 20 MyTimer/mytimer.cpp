#include "mytimer.h"
#include "ui_mytimer.h"
#include<QTime>
#include<QDebug>

MyTimer::MyTimer(QWidget *parent) : QWidget(parent), ui(new Ui::MyTimer)
{
    ui->setupUi(this);
    qDebug() << startTimer(1000);  //验证返回的是timerID
    startTimer(2000);
    startTimer(3000);
}

MyTimer::~MyTimer()
{
    delete ui;
}

void MyTimer::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == 1)
    {
        ui->pushButton->setText(QTime::currentTime().toString());
    }
    if(event->timerId() == 2)
    {
        ui->pushButton_2->setText(QTime::currentTime().toString());
    }
    if(event->timerId() == 3)
    {
        ui->pushButton_3->setText(QTime::currentTime().toString());
    }
}
