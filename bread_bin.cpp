#include "bread_bin.h"

Bread_Bin::Bread_Bin(int x,int y,QString a): Bin(x,y) {
    // bread_bin_pos_x = 15;
    // bread_bin_pos_y = 1;
    name = a;
}

void Bread_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    if (name == "White Bread"){
        QPixmap bread(":/bread.png");
        painter.drawPixmap(rect(), bread);
    } else if (name == "Whole Wheat Bread"){
        QPixmap bread(":/bread.png");
        painter.drawPixmap(rect(), bread);
    } else {
        QPixmap bread(":/bread.png");
        painter.drawPixmap(rect(), bread);
    }
    return;
}
