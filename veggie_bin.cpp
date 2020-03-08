#include "veggie_bin.h"

Veggie_Bin::Veggie_Bin(int x, int y, QString a)
    : Bin(x,y), name(a) {}

void Veggie_Bin:: paintEvent(QPaintEvent* e){
    QPainter painter(this);
    rect().setX(5);
    rect().setY(5);
    if (name == "Lettuce"){
         QPixmap veggies(":/lettuce.png");
          painter.drawPixmap(20,2,30,40, veggies);
    } else if (name == "Peppers"){
        QPixmap veggies(":/pepper.png");
       painter.drawPixmap(20,2,20,40, veggies);
    } else {
        QPixmap veggies(":/spinach.png");
        painter.drawPixmap(20,2,25,40, veggies);
    }
    return;
}
