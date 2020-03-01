#include "cheese_bin.h"

Cheese_Bin::Cheese_Bin(int x,int y, QString a) : Bin(x,y) {
    name = a;
}

void Cheese_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    if (name == "American Cheese") {
        QPixmap cheese(":/cheese.png");
        painter.drawPixmap(rect(), cheese);
    } else if(name == "Swiss Cheese"){
        QPixmap cheese(":/cheese.png");
        painter.drawPixmap(rect(), cheese);
    } else{
        QPixmap cheese(":/cheese.png");
        painter.drawPixmap(rect(), cheese);
    }
    return;
}
