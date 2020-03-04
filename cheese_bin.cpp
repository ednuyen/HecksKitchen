#include "cheese_bin.h"

Cheese_Bin::Cheese_Bin(int x,int y, QString a) : Bin(x,y) {
    name = a;
}

void Cheese_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    if (name == "American Cheese") {
        QPixmap cheese(":/cheese.png");
        painter.drawPixmap(2,2,40,40, cheese);
    } else if(name == "Swiss Cheese"){
        QPixmap cheese(":/cheese.png");
        painter.drawPixmap(2,2,40,40, cheese);
    } else{
        QPixmap cheese(":/cheese.png");
        painter.drawPixmap(2,2,40,40, cheese);
    }
    return;
}
