#ifndef MYTIMER_H
#define MYTIMER_H

#include <QWidget>

namespace Ui {
class MyTimer;
}

class MyTimer : public QWidget
{
    Q_OBJECT

public:
    explicit MyTimer(QWidget *parent = 0);
    ~MyTimer();

protected:
    void timerEvent(QTimerEvent *event);
private:
    Ui::MyTimer *ui;
};

#endif // MYTIMER_H
