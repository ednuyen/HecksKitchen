#include "target.h"

Target::Target(QWidget *parent)
    : QWidget(parent) {
}

void Target:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    QPixmap player(":/target.png");
    player = player.scaled(this->size(), Qt::KeepAspectRatio);
    painter.drawPixmap(rect(), player);
    return;
}
