#ifndef CHEESE_BIN_H
#define CHEESE_BIN_H
#include <QMainWindow>
#include <QPainter>
#include "bin.h"

class Cheese_Bin : public Bin {
public:
    Cheese_Bin(int, int,QString);
    void paintEvent(QPaintEvent* e);
private:
    QString name;
};

#endif // CHEESE_BIN_H
