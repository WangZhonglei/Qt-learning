#include<QMessageBox>
#include "combobox.h"
#include "ui_combobox.h"

ComboBox::ComboBox(QWidget *parent) : QWidget(parent), ui(new Ui::ComboBox)
{
    ui->setupUi(this);
    //查Combobox可看到有3个添加item的函数
    QStringList items;
    items.append("Qt");
    items.append("VS");
    ui->comboBox->addItems(items);

    connect(ui->checkBox, SIGNAL(clicked(bool)), ui->comboBox, SLOT(setDisabled(bool)));

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(onGetComboText()));
}

ComboBox::~ComboBox()
{
    delete ui;
}

void ComboBox::onGetComboText()
{
    QMessageBox::information(this, "Title", ui->comboBox->currentText());
}
