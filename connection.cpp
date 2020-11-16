#include "connection.h"
#include<QSqlDatabase>
Connection::Connection()
{

}
bool Connection::OuvrirConnection()
{

    bool test=false;

 db=QSqlDatabase ::addDatabase("QODBC");
db.setDatabaseName("Projet_2A");
db.setUserName("Rima");
db.setPassword("rima");

if(db.open())
return true;
return test;

}

void Connection::FermerConnection()
{
    db.close();
}
