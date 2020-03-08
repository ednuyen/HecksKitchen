#ifndef FIRE_H
#define FIRE_H
#include <QMainWindow>
#include <QPainter>
#include "bin.h"

class Fire : public Bin {
public:
    Fire(int,int);
    Fire( Fire &a);
    void paintEvent(QPaintEvent* e);
    Fire* set_random_location();
private:
    int rand_num=0;

};
#endif // FIRE_H
