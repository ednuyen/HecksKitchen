#include "cheese_bin.h"

Cheese_Bin::Cheese_Bin(int x,int y) : Bin(x,y) {}

void Cheese_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    QPixmap cheese(":/cheese.png");
    cheese = cheese.scaled(this->size(), Qt::IgnoreAspectRatio);
    painter.drawPixmap(rect(), cheese);
    return;
}
