#ifndef HEALTH_H
#define HEALTH_H
#include <QMainWindow>
#include <QLabel>
#include <QPainter>

class Health : public QWidget {
public:
    Health(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* e);
    QLabel get_health_text();
    void change_health_bar();
private:
    qreal health_value = 10;
    QLabel* health_text;
};

#endif // HEALTH_H
