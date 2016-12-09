#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.setFixedSize(460,560);
    w.setMinimumSize(470,470);
    w.setWindowTitle("Puzla");
    w.show();


    return a.exec();
}
