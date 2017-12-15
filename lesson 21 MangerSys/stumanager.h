#ifndef STUMANAGER_H
#define STUMANAGER_H

#include <QWidget>

namespace Ui {
class StuManager;
}

class StuManager : public QWidget
{
    Q_OBJECT

public:
    explicit StuManager(QWidget *parent = 0);
    ~StuManager();

private:
    Ui::StuManager *ui;
};

#endif // STUMANAGER_H
