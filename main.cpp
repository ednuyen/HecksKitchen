#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w1;
    SecondWindow w2;
    w1.setPartner(&w2);
    w2.setPartner(&w1);
    w1.show();
    return a.exec();
}
