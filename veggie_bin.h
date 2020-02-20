#ifndef VEGGIE_BIN_H
#define VEGGIE_BIN_H
#include <QMainWindow>
#include <QPainter>
#include "bin.h"

class Veggie_Bin : public Bin {
public:
    Veggie_Bin(int,int);
    void paintEvent(QPaintEvent* e);
};


#endif // VEGGIE_BIN_H
