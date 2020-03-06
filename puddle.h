#ifndef PUDDLE_H
#define PUDDLE_H
#include <QMainWindow>
#include <QPainter>
#include "bin.h"

class Puddle : public Bin {
public:
    Puddle(int,int);
    Puddle( Puddle &a);
    void paintEvent(QPaintEvent* e);
    Puddle* set_random_location();
private:
    int rand_num=0;
};
#endif // PUDDLE_H
