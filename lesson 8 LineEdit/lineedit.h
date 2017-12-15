#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QMainWindow>

namespace Ui {
class LineEdit;
}

class LineEdit : public QMainWindow
{
    Q_OBJECT

public:
    explicit LineEdit(QWidget *parent = 0);
    ~LineEdit();

private slots:
    void onClearContents();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::LineEdit *ui;
};

#endif // LINEEDIT_H
