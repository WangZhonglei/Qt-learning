#ifndef MYBTN_H
#define MYBTN_H

#include <QDialog>
#include<QEvent>

namespace Ui
{
class MyBtn;
}

class MyBtn : public QDialog
{
    Q_OBJECT

public:
    explicit MyBtn(QWidget *parent = 0);
    ~MyBtn();

private slots:
    void on_pushButton1_clicked();
    void onBtn2();  //首先手动添加槽函数，然后右键Refactor添加定义
    //void enterEvent(QEvent *event);  //鼠标进入
    //void leaveEvent(QEvent *event);  //鼠标离开
    bool eventFilter(QObject *, QEvent *);

private:
    Ui::MyBtn *ui;
};

#endif // MYBTN_H
