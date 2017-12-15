#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QWidget>
#include<QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUi();

    createCornerBtn();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUi()
{
    m_pStuManager = new StuManager;
    ui->tabWidget->addTab(m_pStuManager, tr("学生管理"));

    m_pTeaManager = new TeaManager;
    ui->tabWidget->addTab(m_pTeaManager, tr("教师管理"));
    //调按钮的高度和宽度
    ui->tabWidget->setStyleSheet("QTabBar::tab{min-width:30ex; min-height:12ex;}");

}

void MainWindow::createCornerBtn()
{
    QPushButton *btnFresh = new QPushButton(tr("刷新"));
    QPushButton *btnAdd = new QPushButton(tr("添加"));
    QPushButton *btnEdit = new QPushButton(tr("编辑"));
    QPushButton *btnDel = new QPushButton(tr("删除"));
    QWidget *cornerWidget = new QWidget;
    //设置4个按钮为水平布局
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(btnFresh);
    hLayout->addWidget(btnAdd);
    hLayout->addWidget(btnEdit);
    hLayout->addWidget(btnDel);

    //把layout放到cornerWidget上面去
    cornerWidget->setLayout(hLayout);
    //把widget放到右上角
    ui->tabWidget->setCornerWidget(cornerWidget, Qt::TopRightCorner);

}
