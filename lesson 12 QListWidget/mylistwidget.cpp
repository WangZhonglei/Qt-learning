#include "mylistwidget.h"
#include "ui_mylistwidget.h"
#include<QListWidgetItem>
#include<QMessageBox>  //消息弹出框

MyListWidget::MyListWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MyListWidget)
{
    ui->setupUi(this);

    setWindowTitle(tr("Device State"));  //设置窗口标题
    for(int row = 0; row <= 20; ++row)
    {
        QListWidgetItem *item = new QListWidgetItem("Device: " + QString::number(row));  //文字
        item->setCheckState(Qt::Unchecked);  //设置可选的状态
        ui->listWidget->addItem(item);  //把item加入到QListWidget上去
    }
    //槽函数和界面按钮绑定
    connect(ui->pushButton_1, SIGNAL(clicked(bool)), this, SLOT(onOkBtn(bool)));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(onCancelBtn(bool)));

    setFixedSize(250, 400);  //设置窗口大小
}

MyListWidget::~MyListWidget()
{
    delete ui;
}

void MyListWidget::onOkBtn(bool)
{
    int rowCount =ui->listWidget->count();  //捕获了item的个数
    QString checkedItems;
    //获取勾选的item
    for(int row = 0; row < rowCount; ++row)
    {
        //获取每个item的状态，判断是否选中
        if(ui->listWidget->item(row)->checkState() == Qt::Checked)
        {
            //保存选中的item文本
            checkedItems += ui->listWidget->item(row)->text() + "\n";
        }
    }

    //this是指定父窗口的作用，如果指定的话，父窗口的样式会影响到QMessageBox上，使用NULL就是原生的样式了。把捕获的文本放入消息框弹出来
    QMessageBox::information(this, "Info", checkedItems);
}

void MyListWidget::onCancelBtn(bool)
{
    close();
}
