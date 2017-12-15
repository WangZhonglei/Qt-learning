#include "tablewidget.h"
#include "ui_tablewidget.h"

TableWidget::TableWidget(QWidget *parent) : QWidget(parent), ui(new Ui::TableWidget)
{
    ui->setupUi(this);

    ui->Search->setMaximumWidth(200);
    //在空槽中显示默认字符
    ui->Search->setPlaceholderText("Search...");

    ui->tableWidget->setRowCount(5);  //设置行
    ui->tableWidget->setColumnCount(15);  //列
    ui->tableWidget->setAlternatingRowColors(true);  //设置行自动变色
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //对选中的单元格变色
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置可变行宽
}

TableWidget::~TableWidget()
{
    delete ui;
}

void TableWidget::on_BtnAdd_clicked()
{
    //添加行
    int currentRow = ui->tableWidget->currentRow();
    ui->tableWidget->insertRow(currentRow+1);
}

void TableWidget::on_BtnDel_clicked()
{
    //删除行
    int currentRow = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(currentRow);
}

//如果QLineEdit的文字改变了，就会执行搜索
void TableWidget::on_Search_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()) //如果为空，则显示所有行
    {
        int rowCount = ui->tableWidget->rowCount();
        for(int row = 0; row < rowCount; row++)
        {
            ui->tableWidget->showRow(row);
        }
        return;
    }

    //获取行列数，循环每一个格子
    int rowCount = ui->tableWidget->rowCount();
    int columnCount = ui->tableWidget->columnCount();
    for(int row = 0; row <rowCount; row++)
    {
        QString rowData;

        for(int column = 0; column < columnCount; column++)
        {
            //取每一行的所有单元格的数据，存取
            if(ui->tableWidget->item(row,column))
            {
                rowData += ui->tableWidget->item(row,column)->text();
            }
        }
        if(!rowData.isEmpty())  //有数据，则判断
        {
            if(rowData.contains(arg1))
            {
                ui->tableWidget->showRow(row);
            }
            else
            {
                ui->tableWidget->hideRow(row);
            }
        }
        else   //无数据
        {
            ui->tableWidget->hideRow(row);
        }
    }
}
