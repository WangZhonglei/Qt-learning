#ifndef MODELVIEW_H
#define MODELVIEW_H

#include <QWidget>
#include<QStandardItemModel>

namespace Ui {
class ModelView;
}

class ModelView : public QWidget
{
    Q_OBJECT

public:
    explicit ModelView(QWidget *parent = 0);
    ~ModelView();

private slots:
    void onBtnClear();

private:
    Ui::ModelView *ui;

    QStandardItemModel *m_pModel;
};

#endif // MODELVIEW_H
