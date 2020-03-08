#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w1;
    SecondWindow w2;
    RecipeWindow w3;
    Lose w4;
    Win w5;
    w1.setPartner(&w2);
    w2.setPartner(&w1, &w3, &w4, &w5);
    w3.setPartner2(&w2);
    w4.setPartner3(&w1);
    w5.setPartner4(&w1);

    w1.show();

    return a.exec();
}
