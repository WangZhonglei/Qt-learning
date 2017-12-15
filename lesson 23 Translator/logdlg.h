#ifndef LOGDLG_H
#define LOGDLG_H

#include <QDialog>
#include<QTranslator>
#include<QEvent>

namespace Ui {
class Logdlg;
}

class Logdlg : public QDialog
{
    Q_OBJECT

public:
    explicit Logdlg(QWidget *parent = 0);
    ~Logdlg();

    void changeEvent(QEvent *event);

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::Logdlg *ui;

    QTranslator *m_PTranslate;

    bool m_IsCN;
};

#endif // LOGDLG_H
