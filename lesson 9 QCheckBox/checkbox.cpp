#include<QMessageBox>
#include "checkbox.h"
#include "ui_checkbox.h"

CheckBox::CheckBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckBox)
{
    ui->setupUi(this);
    //setCheckState接口，设置选中状态
    ui->checkBox->setCheckState(Qt::PartiallyChecked);
}

CheckBox::~CheckBox()
{
    delete ui;
}

void CheckBox::on_pushButton_clicked()
{
    //checkState接口获取复选框状态
    if(ui->checkBox->checkState() == Qt::Checked)
    {
        QMessageBox::information(this,"Informagtion","Checked");
    }
    else if(ui->checkBox->checkState() == Qt::Unchecked)
    {
        QMessageBox::information(this,"Information","Unchecked");
    }
    else if(ui->checkBox->checkState() == Qt::PartiallyChecked)
    {
        QMessageBox::information(this,"Information","PartiallyChecked");
    }
}

void CheckBox::on_pushButton_2_clicked()
{
    if(ui->checkBox_2->checkState() == Qt::Checked)
    {
        ui->checkBox_2->setCheckState(Qt::Unchecked);
    }
    else if(ui->checkBox_2->checkState() == Qt::Unchecked)
    {
        ui->checkBox_2->setCheckState(Qt::Checked);
    }
}
