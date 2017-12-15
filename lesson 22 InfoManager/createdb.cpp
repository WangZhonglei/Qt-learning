#include "createdb.h"
#include <QSqlDatabase>  //用于创建、连接数据库
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

CreateDb::CreateDb()
{

}

void CreateDb::initDB()
{
    //QSqlDatabase用来连接数据库，下面是例子的拷贝
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //参数是数据库的型号
    db.setHostName("DbName.db");
    db.setDatabaseName(":/new/prefix1/Application/DbName.db");
    bool ok = db.open();
    //判断是否成功打开
    if(ok)
    {
        qDebug()<<"Create DB";

        QSqlQuery query;  //用于执行sql语句
        //创建表
        query.exec("create table StuManager (create_date datetime, "
                   "id varchar(20)  primary key, name varchar(20) ,"
                   " sex varchar(20) ,age INTEGER ,"
                   "address varchar(20) , phone varchar(12) , description varchar(50))");


    }
    else
    {
        qDebug()<<db.databaseName();
    }
}

QList<QStringList> CreateDb::selectDataFromBase()
{
    QSqlQuery query("SELECT * FROM StuManager");

    QList<QStringList> stuInfo;

    //遍历表中的所有数据
    while (query.next())
    {
        QStringList rowData ;

        rowData <<query.value(2).toString();
        rowData <<query.value(1).toString();
        rowData <<query.value(3).toString();
        rowData <<query.value(4).toString();
        rowData <<query.value(5).toString();
        rowData <<query.value(6).toString();
        rowData <<query.value(7).toString();
        rowData <<query.value(8).toString();

        stuInfo.append(rowData);
    }
    return stuInfo;
}

