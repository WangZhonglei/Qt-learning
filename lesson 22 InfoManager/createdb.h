#ifndef CREATEDB_H
#define CREATEDB_H

#include <QList>
#include <QStringList>

class CreateDb
{
public:
    CreateDb();

    void initDB();
    //查询数据库，并返回给调用者
    QList<QStringList> selectDataFromBase();

};

#endif // CREATEDB_H
