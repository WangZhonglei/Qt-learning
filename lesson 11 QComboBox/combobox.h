#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QWidget>

namespace Ui {
class ComboBox;
}

class ComboBox : public QWidget
{
    Q_OBJECT

public:
    explicit ComboBox(QWidget *parent = 0);
    ~ComboBox();
private slots:
    void onGetComboText();

private:
    Ui::ComboBox *ui;
};

#endif // COMBOBOX_H
