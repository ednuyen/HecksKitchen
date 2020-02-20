#ifndef TARGET_H
#define TARGET_H
#include <QMainWindow>
#include <QPainter>

class Target:public QWidget {
public:
    Target(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* e);
};

#endif // TARGET_H
