#include "health.h"

Health::Health(QWidget *parent)
    : QWidget(parent) {
    health_value = 10;
    health_text = new QLabel("Health: ");
}

void Health:: paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::red));
    QRectF pff(0,0,10,1);
    painter.drawRect(pff);
    return;
}
