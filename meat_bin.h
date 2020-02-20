#ifndef MEAT_BIN_H
#define MEAT_BIN_H
#include <QMainWindow>
#include <QPainter>
#include"bin.h"

class Meat_Bin : public Bin{
public:
    Meat_Bin(int,int);
    void paintEvent(QPaintEvent* e);
};

#endif // MEAT_BIN_H
