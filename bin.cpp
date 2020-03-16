#include "bin.h"

Bin::Bin() : pos_x(0), pos_y(0) {}

Bin::Bin(int x, int y) : pos_x(x), pos_y(y) {}

int Bin::get_bin_pos_x() const { return pos_x; }

int Bin::get_bin_pos_y() const { return pos_y; }

void Bin::set_bin_pos_x(const int& a) { pos_x = a; }

void Bin::set_bin_pos_y(const int& a) { pos_y = a; }

void Bin::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap player(":/bin.png");
    player = player.scaled(this->size(), Qt::KeepAspectRatio);
    painter.drawPixmap(2,2,30,35, player);
    return;
}

Bin::Bin(const Bin &a){
    pos_x = a.pos_x;
    pos_y = a.pos_y;
}
