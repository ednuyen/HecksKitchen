#include "veggie_bin.h"

Veggie_Bin::Veggie_Bin(int x, int y, QString a)
    : Bin(x,y){
    name = a;
}

void Veggie_Bin:: paintEvent(QPaintEvent* e){
    QPainter painter(this);
    rect().setX(5);
    rect().setY(5);
    if (name == "Lettuce"){
         QPixmap veggies(":/veggies.png");
          painter.drawPixmap(2,2,40,40, veggies);
    } else if (name == "Peppers"){
        QPixmap veggies(":/veggies.png");
       painter.drawPixmap(2,2,40,40, veggies);
    } else {
        QPixmap veggies(":/veggies.png");
        painter.drawPixmap(2,2,40,40, veggies);
    }
    return;
}
