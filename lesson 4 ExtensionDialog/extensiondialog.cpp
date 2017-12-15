#include<QLayout>
#include "extensiondialog.h"
#include "ui_extensiondialog.h"

ExtensionDialog::ExtensionDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ExtensionDialog)
{
    ui->setupUi(this);
    //有些按钮默认是隐藏的
    ui->groupBox_2->hide();
    //将对话框的布局设置为固定大小的布局，这样拖拽就不会改变其大小
    layout()->setSizeConstraint(QLayout::SetFixedSize);
}

ExtensionDialog::~ExtensionDialog()
{
    delete ui;
}

void ExtensionDialog::on_pushButton_3_clicked()
{
    //判断按钮是隐藏还是显示
    if(ui->groupBox_2->isVisible())
    {
        ui->groupBox_2->hide();
        ui->pushButton_3->setText("详细信息<<<");
    }
    else
    {
        ui->groupBox_2->show();
        ui->pushButton_3->setText("详细信息>>>");
    }
}
