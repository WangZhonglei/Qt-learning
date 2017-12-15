#include "widget.h"
#include <QApplication>
#include<QSplitter>
#include<QTreeView>
#include<QListView>
#include<QFileSystemModel>
#include<QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    //分裂器将界面分割为左右两部分
    QSplitter *spliter = new QSplitter;

    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    QTreeView *treeView = new QTreeView(spliter);
    treeView->setModel(model);  //将视图和模型绑定
    treeView->setRootIndex(model->index(QDir::currentPath()));

    QListView *listView = new QListView(spliter);
    listView->setModel(model);
    listView->setRootIndex(model->index(QDir::currentPath()));


    spliter->show();

    return a.exec();
}
