#ifndef TEAMANAGER_H
#define TEAMANAGER_H

#include <QWidget>

namespace Ui {
class TeaManager;
}

class TeaManager : public QWidget
{
    Q_OBJECT

public:
    explicit TeaManager(QWidget *parent = 0);
    ~TeaManager();

private:
    Ui::TeaManager *ui;
};

#endif // TEAMANAGER_H
