#include "cheese_bin.h"

Cheese_Bin::Cheese_Bin(int x,int y, QString _name) : Bin(x,y), name(_name) {}

void Cheese_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    // Draws image of specific type of cheese if the string 'name' matches
    if (name == "American Cheese") {
        QPixmap cheese(":/american.png");
        painter.drawPixmap(15,0,30,40, cheese);
    } else if (name == "Swiss Cheese") {
        QPixmap cheese(":/swiss.png");
        painter.drawPixmap(15,0,30,40, cheese);
    } else {
        QPixmap cheese(":/vegan.png");
        painter.drawPixmap(15,0,30,40, cheese);
    }
    return;
}
