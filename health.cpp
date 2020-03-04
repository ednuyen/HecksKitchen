#include "health.h"

Health::Health(QWidget *parent)
    : QWidget(parent) {
    health_value = 100;
//    health_text = new QLabel("Health");
}

void Health:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::red));
    QRectF pff(0,0,health_value,10);
    painter.drawRect(pff);
    return;
}

void Health::change_health_bar(){
    health_value = health_value-10;
    update();
}
