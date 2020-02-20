#include "bread_bin.h"

Bread_Bin::Bread_Bin(int x,int y): Bin(x,y) {
    // bread_bin_pos_x = 15;
    // bread_bin_pos_y = 1;
}

void Bread_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    QPixmap bread(":/bread.png");
    bread = bread.scaled(this->size(), Qt::IgnoreAspectRatio);
//    bread = bread.scaled(20,20, Qt::IgnoreAspectRatio);
    painter.drawPixmap(rect(), bread);
    return;
}
