#include<QDebug>
#include<QTreeWidgetItem>
#include<QInputDialog>
#include<QMessageBox>
#include "treewidget.h"
#include "ui_treewidget.h"

TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent), ui(new Ui::TreeWidget)
{
    ui->setupUi(this);
    //设置两个Label的宽度
    ui->SchoolLabel->setMinimumWidth(150);
    ui->ClassLabel->setMinimumWidth(150);

    ui->treeWidget->setHeaderLabel("Scool/Class");

    connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(onSetLabelText(QTreeWidgetItem*,int)));

    initTreeWidget();
    createMenu();
}

TreeWidget::~TreeWidget()
{
    delete ui;
}

//对tree进行初始化
void TreeWidget::initTreeWidget()
{
    {
        QTreeWidgetItem *JinNiuSchool = new QTreeWidgetItem(ui->treeWidget);
        JinNiuSchool->setText(0,"Jin Niu School");

        QTreeWidgetItem *JinNiuClassone = new QTreeWidgetItem(JinNiuSchool);
        JinNiuClassone->setText(0,"Jin Niu Class one");

        QTreeWidgetItem *JinNiuClasstwo = new QTreeWidgetItem(JinNiuSchool);
        JinNiuClasstwo->setText(0,"Jin Niu Class two");

        QTreeWidgetItem *JinNiuClassthree = new QTreeWidgetItem(JinNiuSchool);
        JinNiuClassthree->setText(0,"Jin Niu Class three");
    }

    {
        QTreeWidgetItem *QingYangSchool = new QTreeWidgetItem(ui->treeWidget);
        QingYangSchool->setText(0,"Qing Yang School");

        QTreeWidgetItem *QingYangClassone = new QTreeWidgetItem(QingYangSchool);
        QingYangClassone->setText(0,"Qing Yang Class one");

        QTreeWidgetItem *QingYangClasstwo = new QTreeWidgetItem(QingYangSchool);
        QingYangClasstwo->setText(0,"Qing Yang Class two");

        QTreeWidgetItem *QingYangClassthree = new QTreeWidgetItem(QingYangSchool);
        QingYangClassthree->setText(0,"Qing Yang Class three");
    }
}

void TreeWidget::createMenu()
{
    m_PopMenu = new QMenu;

    m_AddMenu = new QMenu;
    m_AddMenu->setIcon(QIcon(":/new/prefix1/Add.png"));
    m_AddMenu->setTitle("Add Action");
    m_AddSchoolAction = new QAction("Add School");
    m_AddClassAction = new QAction("Add Class");

    m_AddMenu->addAction(m_AddSchoolAction);
    m_AddMenu->addAction(m_AddClassAction);

    m_DelAction = new QAction("Del Action");
    m_DelAction->setIcon(QIcon(":/new/prefix1/Del.png"));

    m_PopMenu->addMenu(m_AddMenu);
    m_PopMenu->addAction(m_DelAction);

    connect(m_AddSchoolAction, SIGNAL(triggered(bool)), this, SLOT(onAddSchool()));
    connect(m_AddClassAction, SIGNAL(triggered(bool)), SLOT(onAddClass()));
    connect(m_DelAction, SIGNAL(triggered(bool)),SLOT(onDelAction(bool)));
}

void TreeWidget::contextMenuEvent(QContextMenuEvent *)
{
    if(ui->treeWidget->hasFocus())
    {
        m_PopMenu->move(cursor().pos());
        m_PopMenu->show();
    }
}

void TreeWidget::onSetLabelText(QTreeWidgetItem *item, int)
{
//    qDebug() << "Item Click";
    if(item->parent())
    {
        ui->SchoolLabel->setText(item->parent()->text(0));
        ui->ClassLabel->setText(item->text(0));
    }
    else
    {
        ui->SchoolLabel->setText(item->text(0));
        ui->ClassLabel->setText("Did not choose class");
    }
}

void TreeWidget::onAddSchool()
{
    //添加学校
    qDebug()<<"Add School";

    bool ok;
    QString schoolText = QInputDialog::getText(this, tr("Input School Name"), tr("School Name:"), QLineEdit::Normal, "", &ok);

    if(ok && !schoolText.isEmpty())
    {
        QTreeWidgetItem *schoolItem = new QTreeWidgetItem(ui->treeWidget);
        schoolItem->setText(0,schoolText);
    }
}

void TreeWidget::onAddClass()
{
    //添加班级
    QTreeWidgetItem *currentItem = ui->treeWidget->currentItem();
    if(!currentItem)
    {
        QMessageBox::information(this, "Information", "Did not choose school");
        return;
    }
    if(currentItem->parent())  //选择的是子项：班级
    {
        bool ok;
        QString classText = QInputDialog::getText(this, tr("Input Class Name"), tr("Class Name:"), QLineEdit::Normal, "", &ok);

        if(ok && !classText.isEmpty())
        {
            QTreeWidgetItem *classItem = new QTreeWidgetItem(currentItem->parent());
            classItem->setText(0, classText);
        }
    }
    else   //选择的是顶层：学校
    {
        bool ok;
        QString classText = QInputDialog::getText(this, tr("Input Class Name"), tr("Class Name:"), QLineEdit::Normal, "", &ok);

        if(ok && !classText.isEmpty())
        {
            QTreeWidgetItem *classItem = new QTreeWidgetItem(currentItem);
            classItem->setText(0, classText);
        }
    }
}

void TreeWidget::onDelAction(bool)
{
    //删除学校、班级
    QTreeWidgetItem *currentItem = ui->treeWidget->currentItem();
    if(currentItem->parent())  //选择的是班级
    {
        currentItem->parent()->removeChild(currentItem);
    }
    else
    {
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(currentItem));
    }
}

