#ifndef VEGGIE_BIN_H
#define VEGGIE_BIN_H
#include <QMainWindow>
#include <QPainter>
#include "bin.h"

class Veggie_Bin : public Bin {
public:
    Veggie_Bin(int,int, QString);
    void paintEvent(QPaintEvent* e);
private:
     QString name;
};

#endif // VEGGIE_BIN_H
