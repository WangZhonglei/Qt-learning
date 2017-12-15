#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QDialog>

namespace Ui {
class CheckBox;
}

class CheckBox : public QDialog
{
    Q_OBJECT

public:
    explicit CheckBox(QWidget *parent = 0);
    ~CheckBox();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CheckBox *ui;
};

#endif // CHECKBOX_H
