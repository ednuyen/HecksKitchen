#ifndef CHEESE_BIN_H
#define CHEESE_BIN_H
#include <QMainWindow>
#include <QPainter>
#include "bin.h"

class Cheese_Bin : public Bin {
public:
    Cheese_Bin(int, int);
    void paintEvent(QPaintEvent* e);
};

#endif // CHEESE_BIN_H
