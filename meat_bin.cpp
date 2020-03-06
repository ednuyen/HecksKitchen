#include "meat_bin.h"

Meat_Bin::Meat_Bin(int x,int y, QString a)
    : Bin(x,y) {
    name = a;
}

void Meat_Bin:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    rect().setX(2);
    rect().setY(2);
    if (name == "Turkey Meat"){
        QPixmap meat(":/turkey.png");
         //meat = meat.scaled(this->size(), Qt::IgnoreAspectRatio);
         painter.drawPixmap(20,2,30,40, meat);
    }else if( name == "Steak"){
        QPixmap meat(":/steak.png");
        meat = meat.scaled(this->size(), Qt::IgnoreAspectRatio);
        painter.drawPixmap(20,2,30,40, meat);
    }else{
        QPixmap meat(":/impossible.png");
       // meat = meat.scaled(this->size(), Qt::IgnoreAspectRatio);
         painter.drawPixmap(20,2,30,40, meat);
    }
    return;
}
