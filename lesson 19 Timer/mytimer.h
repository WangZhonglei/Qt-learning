#ifndef MYTIMER_H
#define MYTIMER_H

#include <QWidget>
#include<QTimer>

namespace Ui {
class MyTimer;
}

class MyTimer : public QWidget
{
    Q_OBJECT

public:
    explicit MyTimer(QWidget *parent = 0);
    ~MyTimer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void onUpdateLCDNumber1();
    void onUpdateLCDNumber2();

private:
    Ui::MyTimer *ui;

    QTimer *m_Timer1;
    QTimer *m_Timer2;
};

#endif // MYTIMER_H
