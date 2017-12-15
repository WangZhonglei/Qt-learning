#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QWidget>

namespace Ui {
class MyListWidget;
}

class MyListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyListWidget(QWidget *parent = 0);
    ~MyListWidget();

//界面上两个按钮的响应函数，为了信号与槽的参数匹配，加上bool
private slots:
    void onOkBtn(bool);
    void onCancelBtn(bool);

private:
    Ui::MyListWidget *ui;
};

#endif // MYLISTWIDGET_H
