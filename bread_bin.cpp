#include "bread_bin.h"

Bread_Bin::Bread_Bin(int x,int y,QString a): Bin(x,y) {
    // bread_bin_pos_x = 15;
    // bread_bin_pos_y = 1;
    name = a;
}

void Bread_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    if (name == "White Bread"){
        QPixmap bread(":/white.png");
        painter.drawPixmap(20,2,30,40, bread);
    } else if (name == "Whole Wheat Bread"){
        QPixmap bread(":/bread.png");
        painter.drawPixmap(2,2,40,40, bread);
    } else {
        QPixmap bread(":/pretzel.png");
        painter.drawPixmap(20,2,30,40, bread);
    }
    return;
}
