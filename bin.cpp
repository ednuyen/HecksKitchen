#include "bin.h"
Bin::Bin(){
    x = 0;
    y = 0;
}
Bin::Bin(int a, int b){
    x = a;
    y = b;
}

int Bin::get_bin_pos_x() { return x; }

int Bin::get_bin_pos_y() { return y; }

void Bin::set_bin_pos_x(int a) { x=a; }
void Bin::set_bin_pos_y(int a) { y=a; }

void Bin::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap player(":/bin.png");
    player = player.scaled(this->size(), Qt::KeepAspectRatio);
    painter.drawPixmap(2,2,30,35, player);
    return;
}

Bin::Bin(const Bin &a){
    x=a.x;
    y=a.y;
}
