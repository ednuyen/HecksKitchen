#include "cheese_bin.h"

Cheese_Bin::Cheese_Bin(int x,int y, QString a) : Bin(x,y) {
    name = a;
}

void Cheese_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    if (name == "American Cheese") {
        QPixmap cheese(":/american.png");
        painter.drawPixmap(20,2,30,40, cheese);
    } else if(name == "Swiss Cheese"){
        QPixmap cheese(":/swiss.png");
        painter.drawPixmap(20,2,30,40, cheese);
    } else{
        QPixmap cheese(":/vegan.png");
        painter.drawPixmap(20,2,30,40, cheese);
    }
    return;
}
