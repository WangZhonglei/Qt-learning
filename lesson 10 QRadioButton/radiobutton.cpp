#include <QMessageBox>
#include "radiobutton.h"
#include "ui_radiobutton.h"

RadioButton::RadioButton(QWidget *parent) : QDialog(parent), ui(new Ui::RadioButton)
{
    ui->setupUi(this);

    ui->radioButton->setChecked(true);//设置默认
    ui->radioButton_4->setChecked(true);

    ui->radioButton->setDisabled(true); //单选按钮变得无效
    ui->radioButton->setIcon(QIcon(":/new/prefix1/Icon/111.ico"));
}

RadioButton::~RadioButton()
{
    delete ui;
}

void RadioButton::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        QMessageBox::information(this,"爱好",ui->radioButton->text());
    }
    else if(ui->radioButton_2->isChecked())
    {
        QMessageBox::information(this,"爱好",ui->radioButton_2->text());
    }
}

void RadioButton::on_pushButton_2_clicked()
{
    if(ui->radioButton_3->isChecked())
    {
        QMessageBox::information(this,"书籍",ui->radioButton_3->text());
    }
    else if(ui->radioButton_4->isChecked())
    {
        QMessageBox::information(this,"书籍",ui->radioButton_4->text());
    }
}

//toggled当改变单选状态时，就会触发
void RadioButton::on_radioButton_3_toggled(bool checked)
{
    if(checked)
    {
        QMessageBox::information(this,"爱好", ui->radioButton_3->text());
    }
}
