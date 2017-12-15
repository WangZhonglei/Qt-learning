#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include<QMenu>
#include<QAction>
#include<QContextMenuEvent>
#include<QTreeWidgetItem>

namespace Ui
{
class TreeWidget;
}

class TreeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TreeWidget(QWidget *parent = 0);
    ~TreeWidget();

    void initTreeWidget();  //初始化树形控件

    void createMenu();  //创建菜单，弹出菜单

protected:
    void contextMenuEvent(QContextMenuEvent *);

private slots:
    void onSetLabelText(QTreeWidgetItem* item,int);

    void onAddSchool();
    void onAddClass();
    void onDelAction(bool);

private:
    Ui::TreeWidget *ui;

    QMenu *m_PopMenu;
    QMenu *m_AddMenu;

    QAction *m_AddSchoolAction;
    QAction *m_AddClassAction;

    QAction *m_DelAction;
};

#endif // TREEWIDGET_H
