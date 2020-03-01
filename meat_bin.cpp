#include "meat_bin.h"

Meat_Bin::Meat_Bin(int x,int y, QString a)
    : Bin(x,y) {
    name = a;
}

void Meat_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    if (name == "Turkey Meat"){
        QPixmap meat(":/meat.png");
         painter.drawPixmap(rect(), meat);
    }else if( name == "Steak"){
        QPixmap meat(":/meat.png");
        painter.drawPixmap(rect(), meat);
    }else{
        QPixmap meat(":/meat.png");
        painter.drawPixmap(rect(), meat);
    }
    return;
}
