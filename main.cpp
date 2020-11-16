#include "mainwindow.h"

#include <QApplication>
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection C;
    QMessageBox msg;
    bool test=C.OuvrirConnection();
    MainWindow w;
    if (test)
     {
       msg.setText("Connection réussite");
       w.show();
    }
    else msg.setText("Connection impossible");
    msg.exec();

    return a.exec();
}
