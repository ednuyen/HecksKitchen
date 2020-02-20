#include "meat_bin.h"

Meat_Bin::Meat_Bin(int x,int y)
    : Bin(x,y) {
}

void Meat_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    QPixmap meat(":/meat.png");
    meat = meat.scaled(this->size(), Qt::IgnoreAspectRatio);
    painter.drawPixmap(rect(), meat);
    return;
}
