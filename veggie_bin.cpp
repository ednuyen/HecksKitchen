#include "veggie_bin.h"

Veggie_Bin::Veggie_Bin(int x, int y)
    : Bin(x,y){
}

void Veggie_Bin:: paintEvent(QPaintEvent* e){
    QPainter painter(this);
    QPixmap veggies(":/veggies.png");
    veggies = veggies.scaled(this->size(), Qt::IgnoreAspectRatio);
    painter.drawPixmap(rect(), veggies);
    return;
}
