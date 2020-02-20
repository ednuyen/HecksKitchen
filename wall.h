#ifndef WALL_H
#define WALL_H
#include <QMainWindow>
#include <QPainter>

class Wall:public QWidget {
public:
    Wall(QWidget *parent= nullptr);
    void paintEvent(QPaintEvent* e);
};

#endif // WALL_H
