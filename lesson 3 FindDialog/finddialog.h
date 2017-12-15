#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include<QLabel>
#include<QLineEdit>  //编辑框
#include<QPushButton>  //按钮
#include<QCheckBox>  //复选框


class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = 0);
    ~FindDialog();
    //定义信号与槽
signals:
    void findNext(const QString &str,Qt::CaseSensitivity cs);
    void findPrevious(const QString &str,Qt::CaseSensitivity cs);

private slots:
    void onFindClicked();
    void onEnableFindBtn(const QString &text);


private:
    //定义元素
    QLabel *mLabel;  //成员变量最好加m
    QLineEdit *mLineEdit;
    QPushButton *mFindBtn;
    QPushButton *mCloseBtn;
    QCheckBox *mCaseMath;
    QCheckBox *mBackWard;  //定义是否向前搜索

};

#endif // FINDDIALOG_H
