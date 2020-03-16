#include "bread_bin.h"

Bread_Bin::Bread_Bin(const int x, const int y, QString _name): Bin(x,y), name(_name) {}

void Bread_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
     // Draws image of specific type of bread if the string 'name' matches
    if (name == "White Bread") {
        QPixmap bread(":/white.png");
        painter.drawPixmap(20,0,30,40, bread);
    } else if (name == "Whole Wheat Bread") {
        QPixmap bread(":/wholewheat.png");
        painter.drawPixmap(20,0,30,40, bread);
    } else {
        QPixmap bread(":/pretzel.png");
        painter.drawPixmap(20,0,30,40, bread);
    }
    return;
}
