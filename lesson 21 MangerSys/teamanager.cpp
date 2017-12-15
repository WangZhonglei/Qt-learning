#include "teamanager.h"
#include "ui_teamanager.h"

TeaManager::TeaManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeaManager)
{
    ui->setupUi(this);
}

TeaManager::~TeaManager()
{
    delete ui;
}
