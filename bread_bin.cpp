#include "bread_bin.h"

Bread_Bin::Bread_Bin(int x,int y,QString a): Bin(x,y), name(a) {}

void Bread_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    if (name == "White Bread"){
        QPixmap bread(":/white.png");
        painter.drawPixmap(20,2,30,40, bread);
    } else if (name == "Whole Wheat Bread"){
        QPixmap bread(":/wholewheat.png");
        painter.drawPixmap(20,2,30,40, bread);
    } else {
        QPixmap bread(":/pretzel.png");
        painter.drawPixmap(20,2,30,40, bread);
    }
    return;
}
