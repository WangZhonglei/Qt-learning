#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include <QDialog>

namespace Ui {
class RadioButton;
}

class RadioButton : public QDialog
{
    Q_OBJECT

public:
    explicit RadioButton(QWidget *parent = 0);
    ~RadioButton();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_3_toggled(bool checked);

private:
    Ui::RadioButton *ui;
};

#endif // RADIOBUTTON_H
