#ifndef CONNECTION_H
#define CONNECTION_H
#include<QSqlDatabase>

class Connection
{QSqlDatabase db;
public:
    Connection();
    bool OuvrirConnection();
    void FermerConnection();
};

#endif // CONNECTION_H
