#include<QPushButton>
#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    QPushButton *btn = new QPushButton(this);
    btn->setText("UiTest");
}

Dialog::~Dialog()
{

}
