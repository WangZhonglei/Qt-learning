#include "modelview.h"
#include "ui_modelview.h"

ModelView::ModelView(QWidget *parent) : QWidget(parent), ui(new Ui::ModelView)
{
    ui->setupUi(this);

    m_pModel = new QStandardItemModel(20,5);
    m_pModel->setHorizontalHeaderLabels(QStringList() << "Name" <<"Class"<<"Age"<<"Sex"<<"Grade");

    ui->tableView_1->setModel(m_pModel);
    ui->tableView_1->setAlternatingRowColors(true);   //允许隔行变色
    ui->tableView_1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置伸缩的模式
    ui->tableView_1->horizontalHeader()->setStretchLastSection(true);  //设置最后一列贴边

    ui->tableView_2->setModel(m_pModel);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置伸缩的模式
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);  //设置最后一列贴边

    connect(ui->BtnClear, SIGNAL(clicked(bool)), this, SLOT(onBtnClear()));
    showNormal();
}

ModelView::~ModelView()
{
    delete ui;
}

void ModelView::onBtnClear()
{
    int rowCount = m_pModel->rowCount();

    for(int r = rowCount; r >=0; --r)
    {
        m_pModel->removeRow(r);
    }
    for(int r =0; r < rowCount; ++r)
    {
        m_pModel->insertRow(r);
    }
}
