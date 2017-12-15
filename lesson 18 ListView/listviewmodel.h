#ifndef LISTVIEWMODEL_H
#define LISTVIEWMODEL_H

#include <QWidget>
#include<QStandardItemModel>

namespace Ui {
class ListViewModel;
}

class ListViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit ListViewModel(QWidget *parent = 0);
    ~ListViewModel();

private slots:
    void on_BtnOk_clicked();

    void on_BtnCancel_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    void initModel();

private:
    Ui::ListViewModel *ui;

    QStandardItemModel *m_StudentModel;
    QStandardItemModel *m_TeacherModel;
    QStandardItemModel *m_WorkerModel;

};

#endif // LISTVIEWMODEL_H
