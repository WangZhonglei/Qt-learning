#include "mytimer.h"
#include "ui_mytimer.h"
#include<QTimer>
#include<QTime>


MyTimer::MyTimer(QWidget *parent) : QWidget(parent), ui(new Ui::MyTimer)
{
    ui->setupUi(this);

    ui->lcdNumber->setDigitCount(8);  //hh:mm:ss正好占8位
    ui->lcdNumber_2->setDigitCount(8);

    m_Timer1 = new QTimer;
    connect(m_Timer1, SIGNAL(timeout()), this, SLOT(onUpdateLCDNumber1()));
    m_Timer1->setTimerType(Qt::PreciseTimer);  //参数是定时器的一种精度

    m_Timer2 = new QTimer;
    connect(m_Timer2, SIGNAL(timeout()), this, SLOT(onUpdateLCDNumber2()));
    m_Timer2->setTimerType(Qt::PreciseTimer);
    m_Timer2->start(1000);  //默认启动

}

MyTimer::~MyTimer()
{
    delete ui;
}

void MyTimer::on_pushButton_clicked()
{
    if(m_Timer1->isActive())
    {
        m_Timer1->stop();
        ui->pushButton->setText("Start");
    }
    else
    {
        m_Timer1->start(2000);  //2000是2s执行一次
        ui->pushButton->setText("Stop");
    }
}

void MyTimer::on_pushButton_2_clicked()
{
    if(m_Timer2->isActive())
    {
        m_Timer2->stop();
        ui->pushButton_2->setText("Start");
    }
    else
    {
        m_Timer2->start(1000);
        ui->pushButton_2->setText("Stop");
    }
}

void MyTimer::onUpdateLCDNumber1()
{
    QString timeStr = QTime::currentTime().toString("hh:mm:ss");
    ui->lcdNumber->display(timeStr);
}

void MyTimer::onUpdateLCDNumber2()
{
    QString timeStr = QTime::currentTime().toString("hh:mm:ss");
    ui->lcdNumber_2->display(timeStr);
}
