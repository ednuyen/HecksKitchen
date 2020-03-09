/*#include "health.h"

Health::Health(QWidget *parent)
    : QWidget(parent) {
    health_value = 100;
}

void Health::paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    painter.setBrush(QBrush(QColor::fromRgb(255,60,0)));
    painter.setPen(Qt::red);
    QRectF pff(0,5,health_value,10);
    painter.drawRect(pff);
    return;
}

void Health::change_health_bar(int a){
    health_value = health_value-a;
    update();
}

void Health::reset_health(){
    health_value = 100;
}
*/
