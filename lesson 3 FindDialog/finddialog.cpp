#include<QHBoxLayout>  //加入两个布局的头文件
#include<QVBoxLayout>
#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent) : QDialog(parent)
{
    mLabel = new QLabel(tr("Find &What"));  //&是与，按下Alt和W，即可快速定位
    mLineEdit = new QLineEdit;    //输入框
    mLabel->setBuddy(mLineEdit);  //伙伴关系，会自动转移

    mCaseMath = new QCheckBox(tr("Math &Case"));  //显示文本，匹配大小写
    mBackWard = new QCheckBox(tr("Search &BackWard"));  //是否前向搜索

    mFindBtn = new QPushButton(tr("&Find"));
    mFindBtn->setEnabled(false);  //按钮默认不可点击

    mCloseBtn = new QPushButton(tr("Close"));

    //编辑框输入文字，按钮变得可以点击
    connect(mLineEdit,SIGNAL(textChanged(QString)),this,SLOT(onEnableFindBtn(QString)));
    //点击Find，会执行操作
    connect(mFindBtn,SIGNAL(clicked(bool)),this,SLOT(onFindClicked()));
    //关闭按钮，点击触发
    connect(mCloseBtn,SIGNAL(clicked(bool)),this,SLOT(close()));

    QHBoxLayout *leftTopLayout = new QHBoxLayout;  //把12放入一个水平布局
    leftTopLayout->addWidget(mLabel);
    leftTopLayout->addWidget(mLineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;  //将1234放入垂直布局
    leftLayout->addLayout(leftTopLayout);
    leftLayout->addWidget(mCaseMath);
    leftLayout->addWidget(mBackWard);

    QVBoxLayout *rightLayout = new QVBoxLayout;  //把56放入一个垂直布局
    rightLayout->addWidget(mFindBtn);
    rightLayout->addWidget(mCloseBtn);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    setWindowTitle(tr("Find"));
    setLayout(mainLayout);  //把主布局放到对话框上

}

FindDialog::~FindDialog()
{

}

void FindDialog::onFindClicked()
{
    QString text = mLineEdit->text();
    //isChecked是否被按下，来说明是否区分大小写
    Qt::CaseSensitivity cs = mCaseMath->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    //下面的复选框是否选中判断，发送不同的信号
    if(mBackWard->isChecked())  //是否被选中
    {
        emit findPrevious(text,cs);  //参数是文字和是否区分大小写
    }
    else
    {
        emit findNext(text,cs);
    }
    //断开绑定，Find按钮将在查找一次后，持续有效
    disconnect(mLineEdit,SIGNAL(textChanged(QString)),this,SLOT(onEnableFindBtn(QString)));
}

void FindDialog::onEnableFindBtn(const QString &text)
{
    //按钮是否有效取决于编辑框是否有内容
    mFindBtn->setEnabled(!text.isEmpty());
}
