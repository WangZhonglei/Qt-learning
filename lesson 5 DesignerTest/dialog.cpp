#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent)/*, ui(new Ui::Dialog)*/
{
    ui->setupUi(this);
    //让label显示Qt
    ui->label->setText("Qt");
    //pushButton->setText("1234");
}

Dialog::~Dialog()
{
    delete ui;
}
