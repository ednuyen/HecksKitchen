#include "veggie_bin.h"

Veggie_Bin::Veggie_Bin(int x, int y, QString a)
    : Bin(x,y){
    name = a;
}

void Veggie_Bin:: paintEvent(QPaintEvent* e){
    QPainter painter(this);
    if (name == "Lettuce"){
         QPixmap veggies(":/veggies.png");
         painter.drawPixmap(rect(), veggies);
    } else if (name == "Peppers"){
        QPixmap veggies(":/veggies.png");
        painter.drawPixmap(rect(), veggies);
    } else {
        QPixmap veggies(":/veggies.png");
        painter.drawPixmap(rect(), veggies);
    }
    return;
}
