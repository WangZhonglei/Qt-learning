#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stumanager.h"
#include "teamanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initUi();  //初始化界面

    void createCornerBtn();  //在右上创建按钮


private:
    Ui::MainWindow *ui;

    StuManager *m_pStuManager;
    TeaManager *m_pTeaManager;
};

#endif // MAINWINDOW_H
